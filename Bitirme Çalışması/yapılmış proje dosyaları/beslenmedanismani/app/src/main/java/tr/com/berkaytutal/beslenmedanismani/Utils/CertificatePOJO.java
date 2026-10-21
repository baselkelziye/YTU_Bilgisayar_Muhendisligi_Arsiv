package tr.com.berkaytutal.beslenmedanismani.Utils;

/**
 * Created by berka on 28.06.2017.
 */

public class CertificatePOJO {
    private String certificateInstution;
    private String certificateName;
    private int ID;

    public CertificatePOJO(String certificateInstution, String certificateName, int ID) {
        this.certificateInstution = certificateInstution;
        this.certificateName = certificateName;
        this.ID = ID;
    }

    public String getCertificateInstution() {
        return certificateInstution;
    }

    public void setCertificateInstution(String certificateInstution) {
        this.certificateInstution = certificateInstution;
    }

    public String getCertificateName() {
        return certificateName;
    }

    public void setCertificateName(String certificateName) {
        this.certificateName = certificateName;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }
}
