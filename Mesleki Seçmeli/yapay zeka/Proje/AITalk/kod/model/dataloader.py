import codecs
import os
import tqdm


#This function is responsible for loading the dataset and creating a single file with one sentence per line. 
#The code reads the data from train.to and train.from files and combines them to create a single file. 
#It also removes the lines which contain the words 'removed' or 'deleted' in them.
#The resulting file is stored as training_data.txt

def loader(config_path):
    ds = []
    with open(os.path.join(config_path, "data/train.to")) as t, open(os.path.join(config_path, "data/train.from")) as f:
        fr = f.readlines()
        to = t.readlines()
        try:
            for i in tqdm.tqdm(range(len(fr))):
                if "removed" in fr[i] or "deleted" in fr[i] or "removed" in to[i] or "deleted" in to[i] or not fr[i] or not to[i] :
                    continue
                ds.append(fr[i])
                ds.append(to[i])
        except:
            raise Exception("Please Recheck, Number of lines in train.to and train.from datafiles should be same.")
    
    f = codecs.open(os.path.join(config_path, "data/training_data.txt"), "w", "utf-8")
    for ele in ds:
        f.write(ele)
    f.close()

if __name__ == '__main__':
    loader(".")
