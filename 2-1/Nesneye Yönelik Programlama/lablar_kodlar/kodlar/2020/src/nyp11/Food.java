package nyp11;
import java.util.Date;

public class Food implements Item {
	private Date expireDate;

	public Food(Date expireDate) {
		this.expireDate = expireDate;
	}
	public Date getExpireDate() { return expireDate; }
	public boolean isExpired( ) {
		Date today = new Date();
		if( expireDate.before(today) )
			return true;
		 return false;
	}
	public String toString() {
		return "A food expiring at " + expireDate;
	}
}
