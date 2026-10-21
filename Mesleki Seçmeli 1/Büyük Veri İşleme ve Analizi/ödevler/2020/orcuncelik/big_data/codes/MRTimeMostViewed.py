from mrjob.job import MRJob
from mrjob.step import MRStep

#finds most viewed times

class MRTimeMostViewed(MRJob):
    
    def steps(self)  :
      return[
          MRStep(mapper=self.mapper1, reducer=self.reducer1),
          MRStep(mapper = self.mapper2, reducer=self.reducer2)
          ]
    
    def mapper1(self,_,line):
      (time,eventtype,productid,categoryid,categorycode,brand,price,userid,usersession) = line.split(',')
      if (eventtype == 'view'):
          yield time,1
          
    def reducer1(self,time,values):
        yield time, sum(values)
    
    
    def mapper2(self, time, values):
        yield None,('%04d'%int(values), time)
        
      
    def reducer2(self,value, times):
        self.list1 = []
        self.list2 = []
        for time in times:
            self.list1.append(time)           
        for i in range(5):
            self.list2.append(max(self.list1))
            self.list1.remove(max(self.list1))
        for i in range(5):
            yield self.list2[i]
   
      

if __name__ == '__main__':
    MRTimeMostViewed.run() 
