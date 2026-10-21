from mrjob.job import MRJob

#counts event type

class IterableCat(type):
    def __iter__(cls):
        return iter(cls.__name__)

class MRCategories(MRJob):
    __metaclass__ = IterableCat
    
    def mapper(self, _ , line):
        (etime,etype,pid,cid,ccode,brand,price,uid,session) = line.split(',')
        yield etype, 1
        
    def reducer(self,etype,occurences):
        yield etype, sum(occurences)

