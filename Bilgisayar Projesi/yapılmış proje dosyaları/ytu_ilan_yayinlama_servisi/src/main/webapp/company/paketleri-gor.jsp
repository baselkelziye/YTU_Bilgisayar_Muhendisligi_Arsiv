<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>

<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<title>İlan Paketleri</title>
		<jsp:include page="html/head.html"/>

        <script>
            $(document).on("click", ".open-sendRequestModal", function (e) {
                e.preventDefault();
                var _self = $(this);
                var packetID = _self.data('id');
                $("#packetID").val(packetID);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-bankDetail", function (e) {
                e.preventDefault();
                var _self = $(this);

                var iban = _self.data('iban');
                var account = _self.data('account');
                var bank = _self.data('bank');
                var branch = _self.data('branch');
                var unit = _self.data('unit');

                document.getElementById("iban").innerHTML = iban;
                document.getElementById("account").innerHTML = account;
                document.getElementById("bank").innerHTML = bank;
                document.getElementById("branch").innerHTML = branch;
                document.getElementById("unit").innerHTML = unit;

                $(_self.attr('href')).modal('show');
            });

            $(document).ready(function(){
                $('[data-toggle="popover"]').popover();
            });
        </script>
	</head>
	<body>
        <div class="modal fade" id="sendRequestModal" role="dialog">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Bağış Bilgisi Gir</h4>
                    </div>
                    <div class="modal-body">
                        <p>Yapılan bağış ile ilgili bilgileri giriniz.</p>
                        <p>Fatura/ödeme bilgisine ait görüntü veya pdf ekleyiniz.</p>
                        <form method="post" action="../donationrequestservlet" enctype="multipart/form-data">
                            <div class="form-group">
                                <textarea rows="10" cols="40" name="description" class="form-control">Açıklama..</textarea>
                            </div>
                            <div class="form-group">
                                <label for="file">Dosya Yükleyin</label>
                                <input type="file" name="file" id="file"/>
                            </div>
                            <input type="hidden" id="packetID" name="packetId"/>
                            <button type="submit" class="btn btn-default">Gönder</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Verdiğiniz bilgiler yanlışsa, talebiniz reddedilecektir.</p>
                        <p>Bu durumda yeniden istek göndermeniz gerekecektir.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="bankDetail" role="dialog">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Banka Bilgileri</h4>
                    </div>
                    <div class="modal-body">
                        <b>Ödemenin yapılacağı Bağış Kabul Birimi</b>
                        <p id="unit"></p>

                        <b>Banka</b>
                        <p id="bank"></p>

                        <b>Şube</b>
                        <p id="branch"></p>

                        <b>Hesap Numarası</b>
                        <p id="account"></p>

                        <b>IBAN</b>
                        <p id="iban"></p>
                    </div>
                    <div class="modal-footer">
                        <p>Lütfen ödeme yapmadan bağış isteği göndermeyiniz.</p>
                        <p>Banka tarafından yapılacak kesintilere dikkat ediniz.</p>
                        <p>Şu anda kullanılan tek birim Türk Lirası'dır.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

		<jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
			<div class="row">
                <div class="col-md-1"></div>
				<div class="col-md-10">
					<c:choose>
						<c:when test="${donation_request eq 1}">
							<div class="alert alert-success">
								Bağış uyarınız gönderilmiştir.
							</div>
						</c:when>
						<c:when test="${donation_request eq 2}">
							<div class="alert alert-warning">
								Bir hata oluştur lütfen tekrar deneyiniz.
							</div>
						</c:when>
					</c:choose>

					<table class="table table-stripped">
						<thead>
							<tr>
								<th>Paket Başlığı</th>
								<th>Açıklama</th>
								<th>
                                    İlan Sayısı
                                    <a href="../orderpacketstocompany?condition=announcement_count&order=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../orderpacketstocompany?condition=announcement_count&order=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
								<th>
                                    Yayın Süresi(Gün)
                                    <a href="../orderpacketstocompany?condition=active_time&order=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../orderpacketstocompany?condition=active_time&order=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
								<th>
                                    Fiyat(TL)
                                    <a href="../orderpacketstocompany?condition=price&order=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../orderpacketstocompany?condition=price&order=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
								<th>
                                    SKT
                                    <a href="../orderpacketstocompany?condition=last_date_used&order=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../orderpacketstocompany?condition=last_date_used&order=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
								<th>İşlem</th>
							</tr>
						</thead>
						<tbody>
							<c:forEach var="item" items="${packets}">
								<tr>
									<td>${item.title}</td>
                                    <td>
                                        <c:choose>
                                            <c:when test="${fn:length(item.condition) < 20}">
                                                ${item.condition}
                                            </c:when>
                                            <c:otherwise>
                                                ${fn:substring(item.condition, 0, 20)}...
                                                <a href="#" data-toggle="popover" data-placement="right"
                                                   title="Açıklama:" data-content="${item.condition}">
                                                    <span class="glyphicon glyphicon-info-sign "></span>
                                                </a>
                                            </c:otherwise>
                                        </c:choose>
                                    </td>
									<td align="right">${item.announcementCount}</td>
									<td align="right">${item.activeTime}</td>
									<td align="right">${item.price}</td>
									<td><fmt:formatDate  pattern="dd-MM-yyy" value="${item.lastDateUsed}"/></td>
									<td>
                                        <a href="#bankDetail" data-toggle="modal" data-placement="left"
                                           class="open-bankDetail btn btn-success"
                                           data-iban="${item.accountInfo.iban}"
                                           data-account="${item.accountInfo.bankAccountNumber}"
                                           data-unit="${item.accountInfo.ownerUnit.unitName}"
                                           data-bank="${item.accountInfo.bankName}"
                                           data-branch="${item.accountInfo.branchBankName}"
                                           title="Banka Bilgileri">
                                            <span class="glyphicon glyphicon-bold "></span>
                                        </a>
                                        <a data-id="${item.packetId }"
                                           data-toggle="modal"
                                           title="Bağış Yaptım"
                                           class="open-sendRequestModal btn btn-primary"
                                           href="#sendRequestModal">
                                            <span class="glyphicon glyphicon-ok"></span>
                                        </a>
									</td>
								</tr>
							</c:forEach>
						</tbody>
					</table>
				</div>
			</div>
		</div>
	</body>
</html>