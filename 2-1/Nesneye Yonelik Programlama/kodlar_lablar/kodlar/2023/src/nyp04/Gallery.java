package nyp04;

public class Gallery {
	private String galleryName;
	private Car[] cars;
	private int carCount;
	private Person galleryOwner;

	public Gallery( String galleryName, Person galleryOwner, int capacity ) { 
		this.galleryName = galleryName;
		this.galleryOwner = galleryOwner;
		carCount = 0;
		cars = new Car[capacity];
	}
	public String getGalleryName() { return galleryName; }
	public void setGalleryName(String galleryName) { 
		this.galleryName = galleryName; 
	}
	public String introduceSelf( ) {
		String intro = "This is a car gallery named "+ galleryName;
		intro += ",  owned by " + galleryOwner.getName();
		intro += ". There are currently " + carCount + " cars to sell.";
		return intro;
	}
	public boolean addCar( Car aCar ) {
		if( !searchCar(aCar) && carCount < cars.length ) {
			aCar.setOwner(galleryOwner); //optional
			cars[ carCount ] = aCar;
			carCount++;
			return true;
		}
		return false;
	}
	public Car searchCar( String plate ) {
		for( int i = 0; i < carCount; i++ )
			if( cars[i].getPlate().equalsIgnoreCase(plate) )
				return cars[i];
		return null;
	}
	public boolean searchCar( Car aCar ) {
		for( Car car : cars )
			if( car == aCar )
				return true;
		return false;
	}
	public Car removeCar( String plate ) {
		for( int i = 0; i < carCount; i++ ) {
			//we need to search again in here as we need the index of the car
			if( cars[i].getPlate().equalsIgnoreCase(plate) ) {
				Car theCar = cars[i];
				for( int j = i; j < carCount; j++ ) 
					cars[j] = cars[j+1];
				cars[carCount-1] = null; carCount--;
				return theCar;
			}
		}
		return null;
	}
	public boolean sellCar( String plate, Person newOwner ) {
		Car soldCar = removeCar(plate);
		if( soldCar != null ) {
			soldCar.setOwner(newOwner);
			return true;
		}
		return false;
	}
}
