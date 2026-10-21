from tkinter import *

from MRCategories import MRCategories
from MRMostPopular import MRMostPopular
from MRAvgPrice import MRAvgPrice
from MRTimeMostViewed import MRTimeMostViewed

if __name__ == '__main__':
    category = MRCategories()
    popular_brands = MRMostPopular()
    avgprice = MRAvgPrice()
    most_view = MRTimeMostViewed()
    

    root = Tk()
    root.title("User Analytics")
    root.geometry("220x285")
    
    def fun_category():
        category.run()

    def fun_popular():
        popular_brands.run()
        
    def fun_avg():
        avgprice.run()
        
    def fun_view():
        most_view.run()


    button_category = Button(root, text = "Categories", padx = 70, pady = 20,borderwidth = 5, command = fun_category)
    button_category.grid(row = 0, column = 0)
    
    button_popularity = Button(root, text = "Top 5 Brands", padx = 65, pady = 20, borderwidth = 5,command = fun_popular)
    button_popularity.grid(row = 1, column = 0)
    
    button_avg = Button(root, text = "Average Price", padx = 63, pady = 20,borderwidth = 5, command = fun_avg)
    button_avg.grid(row = 2, column = 0)
    
    button_avg = Button(root, text = "Busy Hours",padx = 70, pady = 20,borderwidth = 5,  command = fun_view)
    button_avg.grid(row = 3, column = 0)
    

    root.mainloop()


