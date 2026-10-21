from mrjob.job import MRJob
from mrjob.step import MRStep

#Finds which brands are most viewed

class IterableCat(type):
    def __iter__(cls):
        return iter(cls.__name__)

class MRMostPopular(MRJob):
    def steps(self)  :
      return[
          MRStep(mapper=self.mapper1, reducer=self.reducer1),
          MRStep(mapper = self.mapper2, reducer=self.reducer2)
          ]
    
    def mapper1(self,_,line):
        (time,eventtype,productid,categoryid,categorycode,brand,price,userid,usersession) = line.split(',')
        if eventtype =='view':
            yield brand,1
          
    def reducer1(self,brand,values):
        yield brand, sum(values)

    def mapper2(self, brand, values):
        yield None,('%04d'%int(values), brand)
        
    #list1 stores key,value pairs.
    #list2 stores maximum value 5 pairs
    def reducer2(self,key, brands):
        self.list1 = []
        self.list2 = []
        for brand in brands:
            self.list1.append(brand)           
        for i in range(5):
            self.list2.append(max(self.list1))
            self.list1.remove(max(self.list1))
        for i in range(5):
            yield self.list2[i]
      

