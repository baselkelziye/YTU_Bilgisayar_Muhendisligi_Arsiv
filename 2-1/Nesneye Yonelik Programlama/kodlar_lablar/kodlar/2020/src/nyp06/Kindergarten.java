package nyp06;

public class Kindergarten {
	private Child[] children;
	private int childCount;
	
	public Kindergarten( int maxChild ) {
		children = new Child[maxChild];
		childCount = 0;
	}
	public Child findChild( String name ) {
		for( int i=0; i<childCount; i++ )
			if( children[i].getName().equalsIgnoreCase(name) )
				return children[i];
		return null;
	}
	public boolean addChild( Child aChild ) {
		if( childCount == children.length || aChild == null || 
				findChild(aChild.getName()) != null )
			return false;
		children[childCount]=aChild;
		childCount++;
		return true;
	}
	public Child findOldestChild( ) {
		Child oldest = children[0];
		for( int i=1; i<childCount; i++ )
			if( children[i].getAgeInMonths() > oldest.getAgeInMonths() )
				oldest = children[i];
		return oldest;
	}
	public int getCapacity() {
		return children.length;
	}
	public void setCapacity(int capacity) {
		if( capacity > children.length ) {
			Child newChildren[] = new Child[capacity];
			for( int i=0; i<childCount; i++ )
				newChildren[i] = children[i];
			children = newChildren;
		}
	}
	public Child removeChild( String name ) {
		Child removed;
		for( int i=0; i<childCount; i++ ) {
			if( children[i].getName().equalsIgnoreCase(name) ) {
				removed = children[i];
				for( int j = i+1; j<children.length;j++ ) {
					children[j-1]=children[j];
				}
				return removed;
			}
		}
		return null;
	}
}
