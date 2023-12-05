import os
import tqdm
import yaml
from anytree import Node, NodeMixin, RenderTree
from bs4 import BeautifulSoup as soup
from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException

options = webdriver.ChromeOptions()
options.add_argument("-no-sandbox")
options.add_argument("-headless")
options.add_argument("-disable-dev-shm-usage")
d = webdriver.Chrome("chromedriver", options=options)

class NodeCom(NodeMixin):
  def __init__(self, name, attrs=None, parent=None, children=None):
    super(NodeCom, self).__init__()
    self.name = name
    self.attrs = attrs
    self.parent = parent
    self.children = children if children else []


def get_data(config_path):
    with open(os.path.join(config_path,"reddit_config.yml")) as cf:
      reddit_conf = yaml.load(cf, Loader=yaml.FullLoader)
    SUBREDDIT = reddit_conf["subreddits"]
    HTTPS = reddit_conf["https"]
    SORT = reddit_conf["sort"]
    TIME = reddit_conf["time"]
    PAGES = reddit_conf["no_of_pages"]

    
    posts = []
    for sub in SUBREDDIT:
        link = HTTPS + sub + "/" + SORT + "/?t=" + TIME
        d.get(link)
        for i in range(PAGES):
            wdposts = d.find_elements_by_class_name("thing")
            for wdpost in wdposts:
                html = wdpost.get_attribute("outerHTML")
                htpost = soup(html, "html.parser").div
            
                text = htpost.find("a", class_="title").text
                attrs = htpost.attrs
                attrs["data-score"] = int(attrs["data-score"])
                attrs.update({"text":text, "comments":None})
                posts.append(attrs)
        
            try:
                next = d.find_element_by_class_name("next-button").get_attribute("outerHTML")
            except NoSuchElementException:
                break
            page = soup(next, "html.parser").a.attrs["href"]
            print(i+1, page)
            d.get(page)
    print("Total posts:", len(posts))

    print("Getting comments for the post extracted")
    
    for post in tqdm.tqdm(posts):
        d.get(HTTPS + post["data-permalink"])
        html = d.page_source
        htlist = soup(html, "html.parser").select("div.nestedlisting")
        parent = NodeCom(attrs["data-fullname"], post) 
        recursive(htlist, parent)
        post["comments"] = parent

    data = []
    for prev in tqdm.tqdm(posts):
        for pre, fill, node in RenderTree(prev["comments"]):
            if len(pre) == 0:
                p1 = node.attrs["text"].replace('\n', ' ')
            elif len(pre) == 4:
                p2 = node.attrs["text"].replace('\n', ' ')
                data.append((p1,p2))
            elif len(pre) == 8:
                p3 = node.attrs["text"].replace('\n', ' ')
                data.append((p2,p3))
            elif len(pre) == 12:
                p4 = node.attrs["text"].replace('\n', ' ')
                data.append((p3,p4))
            elif len(pre) == 16:
                p5 = node.attrs["text"].replace('\n', ' ')
                data.append((p4,p5))
            elif len(pre) == 20:
                p6 = node.attrs["text"].replace('\n', ' ')
                data.append((p5,p6))

    if not os.path.exists(os.path.join(config_path, "data")):
        os.mkdir(os.path.join(config_path, "data"))
    
    with open(os.path.join(config_path, "data/train.from"), "w") as f1, open(os.path.join(config_path, "data/train.to") , "w") as f2:
        for x, y in data:
            f1.write("{}\n".format(x))
            f2.write("{}\n".format(y))
        f1.close()
        f2.close()
# Recursively get comments & create tree by linking nodes
def recursive(soup, parent):
  # End recursion if it's empty
  if not soup:
    return
  # Soup is another link opened by soup
  htcoms = soup[0].find_all("div", class_="comment", recursive=False)
  # Iterate through every comment found, set to the same parent
  for htcom in htcoms:
    try:
        attrs = get_comment(htcom)
    except:
        continue
    # Create node. Won't be replaced in the next loop since what matters is the object, not the variable.
    node = NodeCom("a", attrs, parent)
    nxsoup = htcom.select("div.listing")
    recursive(nxsoup, node)

def get_comment(htcom):
  # Get comment & vote count. None = Deleted
  text = htcom.find("div", class_="usertext-body").text
  vote = htcom.find("span", class_="unvoted")
  # Deleted comments. Also automatically None if hidden
  if vote == '':
    vote = None
  if vote != None:
    vote = int(vote.attrs["title"])
  attrs = htcom.attrs # Get everything else (in attribute)
  attrs.update({"text":text, "data-score":vote})
  return attrs

if __name__ == '__main__':
    get_data(".")
