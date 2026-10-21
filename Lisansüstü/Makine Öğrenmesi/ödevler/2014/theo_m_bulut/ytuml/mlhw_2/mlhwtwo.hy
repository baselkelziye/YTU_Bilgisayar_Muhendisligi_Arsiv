
(defn readcsv []
	(with [[f (open "sayi.dat")]]
		(for [ line f ]
		    ((. line rstrip "\n")))))

(readcsv)
(print "Sorry but this is zero performance.")