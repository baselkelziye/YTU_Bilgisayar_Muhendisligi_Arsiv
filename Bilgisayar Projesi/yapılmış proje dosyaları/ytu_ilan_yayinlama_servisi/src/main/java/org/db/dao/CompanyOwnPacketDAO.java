package org.db.dao;

import org.db.model.CompanyOwnPacket;

import java.util.List;

public interface CompanyOwnPacketDAO {
	boolean save(CompanyOwnPacket cop);
	boolean updatePacket(CompanyOwnPacket cop);
	CompanyOwnPacket getPacket(int packetId);
	List<CompanyOwnPacket> getWaitingPacketsToCompany(String companyUserName);
	List<CompanyOwnPacket> getAvailablePackets(String companyUserName);
	List<CompanyOwnPacket> getPacketBySQLQuery(String query);
}
