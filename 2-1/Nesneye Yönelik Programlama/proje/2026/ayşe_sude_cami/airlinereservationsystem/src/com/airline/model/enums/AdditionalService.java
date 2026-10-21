package com.airline.model.enums;

/**
 * Ek hizmet türlerini tanımlar.
 * Her hizmet için isim, sembol ve fiyat bilgisi içerir.
 */
public enum AdditionalService {
	FREE_CANCELLATION("Ücretsiz İptal", "🛡️", 75.0),
	IN_FLIGHT_ENTERTAINMENT("Uçak İçi Eğlence", "🎬", 50.0),
	MEAL_SELECTION("Yemek Seçimi", "🍽️", 45.0),
	EXTRA_BAGGAGE("Ek Bagaj Hakkı", "🧳", 120.0);

	private final String displayName;
	private final String icon;
	private final double price;

	AdditionalService(String displayName, String icon, double price) {
		this.displayName = displayName;
		this.icon = icon;
		this.price = price;
	}

	public String getDisplayName() {
		return displayName;
	}

	public String getIcon() {
		return icon;
	}

	public double getPrice() {
		return price;
	}

	/**
	 * Sembol ve ismi birlikte döndürür.
	 */
	public String getFullLabel() {
		return icon + " " + displayName;
	}

	/**
	 * Fiyat bilgisiyle birlikte tam etiket döndürür.
	 */
	public String getLabelWithPrice() {
		return String.format("%s %s (+%.0f TL)", icon, displayName, price);
	}
}
