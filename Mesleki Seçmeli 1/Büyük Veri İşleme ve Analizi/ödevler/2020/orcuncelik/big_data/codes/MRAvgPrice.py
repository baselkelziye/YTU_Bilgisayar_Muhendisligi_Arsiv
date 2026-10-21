from mrjob.job import MRJob

#finds average price per brand

class MRAvgPrice(MRJob):
    
    def mapper(self,_,line):
        (time,eventtype,productid,categoryid,categorycode,brand,price,userid,usersession) = line.split(',')
        if eventtype == 'view':
            yield brand, price
          
    def reducer(self,brand,values):
        total = 0
        numElement = 0
        for value in values:
            total += float(value)
            numElement += 1
        yield brand, total/numElement
    
    
        
      
