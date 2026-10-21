<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>

<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-9">
		 <jsp:include page="html/head.html"/>
		<title>Paket Detayları</title>
	</head>
	<body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
	        <div class="row">
                <div class="col-md-3"></div>
	            <div class="col-md-6">
                    <a href="../displaypackets" class="btn btn-primary">
                        <span class="glyphicon glyphicon-arrow-left"></span>
                        Listeye Dön
                    </a>
                    <p></p>
	            	<table class="table table-bordered">
                        <tr>
                            <th>Paket No</th>
                            <td>${packet.packetId}</td>
                        </tr>
                        <tr>
                            <th>Bağlı Olduğu Birim</th>
                            <td>${packet.accountInfo.ownerUnit.unitName}</td>
                        </tr>
	            		<tr>
	            			<th>Başlık</th>
	            			<td>${packet.title }</td>
	            		</tr>
	            		<tr>
	            			<th>İlan Sayısı (Adet)</th>
	            			<td>${packet.announcementCount }</td>
	            		</tr>
	            		<tr>
	            			<th>Fiyat (TL)</th>
	            			<td>${packet.price }</td>
	            		</tr>
	            		<tr>
	            			<th>Son Kullanım Tarihi</th>
	            			<td><fmt:formatDate pattern="dd-MM-yyyy" value="${packet.lastDateUsed }"/></td>
	            		</tr>
	            		<tr>
	            			<th>Bir İlan İçin Yayın Süresi (Gün)</th>
	            			<td>${packet.activeTime }</td>
	            		</tr>
	            		<tr>
	            			<th>Açıklama</th>
	            			<td>${packet.condition }</td>
	            		</tr>
	            		<tr>
	            			<th>Tanımlı Banka</th>
	            			<td>${packet.accountInfo.bankName }</td>
	            		</tr>
                        <tr>
                            <th>Şube</th>
                            <td>${packet.accountInfo.branchBankName }</td>
                        </tr>
                        <tr>
                            <th>Hesap Numarası</th>
                            <td>${bankAccountNumber}</td>
                        </tr>
	            		<tr>
	            			<th>IBAN No</th>
	            			<td>${packet.accountInfo.iban}</td>
	            		</tr>
	            	</table>
	            </div>
	        </div>
	    </div>

        <jsp:include page="../html/footer.html"></jsp:include>
	</body>
</html>