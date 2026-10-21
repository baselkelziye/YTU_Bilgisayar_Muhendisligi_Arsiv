<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" type="text/css" href="../css/bootstrap.css">
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<jsp:include page="html/head.html"></jsp:include>
		<title>Onay Bekleyen Bağışlar</title>
	</head>
	<body>
        <script>
            $(document).on("click", ".download-file", function (e) {
                e.preventDefault();
                var _self = $(this);
                var idPath = _self.data('path');
                var idType = _self.data('type');
                $("#path").val(idPath);
                $("#type").val(idType);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-approveRequestModal", function (e) {
                e.preventDefault();
                var _self = $(this);
                var id = _self.data('id');
                $("#packetId").val(id);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-rejectRequestModal", function (e) {
                e.preventDefault();
                var _self = $(this);
                var id = _self.data('id');
                $("#id2").val(id);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".show-message", function (e) {
                e.preventDefault();
                var _self = $(this);
                var message = _self.data('message');
                document.getElementById("m").innerHTML = message;
                $(_self.attr('href')).modal('show');
            });
        </script>

        <div class="modal fade" id="showMessage" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" onclick="nonVisible()">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p><b>Şirket Kullanıcısının Mesajı</b></p>
                        <p id="m"></p>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="downloadFile2" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" onclick="nonVisible()">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>Dosyayı İndir</p>
                        <form>
                            <input type="hidden" name="fileName" id="path">
                            <input type="hidden" name="fileType" id="type">
                            <input formaction="../pdfviewer" type="submit"  class="btn btn-default" value="Evet"/>
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="approveRequestModal" role="dialog">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>Bağışı Onaylamak İstediğinize Emin Misinin?</p>
                        <form action="../approveddonationservlet">
                            <input type="hidden" id="packetId" name="packetId" />
                            <input type="submit"  class="btn btn-default" value="Evet"/>
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>

		<div class="modal fade" id="rejectRequestModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
			<div class="modal-dialog">
				<div class="modal-content">
					<div class="modal-body">
						<p><b>Bağış İsteğini Reddet</b></p>
						<form method="post" action="../rejectdonation">
							<input type="hidden" name="id" id="id2">
                            <div class="form-group">
                                <label>Açıklamanız</label>
                                <textarea rows="5" cols="50" name="content" id="content" class="form-control"></textarea>
                            </div>
							<button type="submit" class="btn btn-default">Gönder</button>
						</form>
					</div>
					<div class="modal-footer">
						<button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
					</div>
				</div>
			</div>
		</div>

	    <jsp:include page="html/menu.html"></jsp:include>
		<div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-2"></div>
                <div class="col-md-5">
                    <c:choose>
                        <c:when test="${onaylandi eq 1}">
                            <div class="alert alert-success">
                                Talebi başarıyla onayladınız.<br/>
                            </div>
                        </c:when>
                        <c:when test="${onaylandi eq 2}">
                            <div class="alert alert-danger">
                                Talep onaylanırken bir hata oluştu.
                                Lütfen daha sonra tekrar deneyiniz.
                            </div>
                        </c:when>
                        <c:when test="${onaylandi eq 3}">
                            <div class="alert alert-success">
                                Talep Reddedildi.
                            </div>
                        </c:when>
                        <c:when test="${onaylandi eq 4}">
                            <div class="alert alert-danger">
                                Talep onaylanırken bir hata oluştu.
                                Lütfen daha sonra tekrar deneyiniz.
                            </div>
                        </c:when>
                    </c:choose>
                </div>
            </div>
			<div class="row">
				<div class="col-md-2"></div>
				<div class="col-md-9">
					<p><b>Onay Bekleyen Bağışlar</b></p>
                    <c:if test="${fn:length(packet) eq 0 }">
                        <p><i>Bekleyen istek yok.</i></p>
                    </c:if>
					<table class="table table-hovered">
						<thead>
							<tr>
								<th>Paket Adı</th>
								<th>Fiyat (TL)</th>
								<th>Şirket Adı</th>
								<th>İstek Yollanan Zaman</th>
								<th>Onay Durumu</th>
								<th>İşlem</th>
							</tr>
						</thead>
						<tbody>
							<c:forEach var="item" items="${packet}">
								<tr>
									<td>${item.packet.title}</td>
									<td align="right">${item.packet.price}</td>
									<td>${item.ownerCompany.companyName}</td>
									<td align="right"><fmt:formatDate pattern="dd-MM-yyy" value="${item.timeToRequest}"/></td>
									<td>
                                        <c:choose>
                                            <c:when test="${item.approved eq false}">
                                                <i>Bekleniyor</i>
                                            </c:when>
                                        </c:choose>
                                    </td>
									<td>
										<a  href="#showMessage"
                                            data-message="İlk Açıklama: ${item.companyDescription} İkinci Açıklama: ${item.secondCompanyDescription}"
                                            title="Mesajı Oku"
                                            data-toogle="modal"
                                            class="show-message btn btn-info">
                                            <span class="glyphicon glyphicon-envelope"></span>
                                        </a>
                                        <c:if test="${item.filePath ne null}">
                                            <a href="#downloadFile2"
                                               title="1.Ödeme belgesini indir"
                                               data-type="ortak"
                                               data-path="${item.filePath}"
                                               class="download-file btn btn-success"
                                               data-toggle="modal"><span class="glyphicon glyphicon-paperclip"></span>
                                            </a>
                                        </c:if>
                                        <c:if test="${item.secondFilePath ne null}">
                                            <a href="#downloadFile2"
                                               title="2.Ödeme belgesini indir"
                                               data-type="ortak"
                                               data-path="${item.secondFilePath}"
                                               class="download-file btn btn-success"
                                               data-toggle="modal"><span class="glyphicon glyphicon-paperclip"></span>
                                            </a>
                                        </c:if>
                                        <a data-id="${item.id }"
                                           data-toggle="modal"
                                           title="Onayla"
                                           class="open-approveRequestModal btn btn-primary"
                                           href="#approveRequestModal">
                                            <span class="glyphicon glyphicon-ok"></span>
                                        </a>
                                        <a data-id="${item.id }"
                                           data-toggle="modal"
                                           title="Reddet"
                                           class="open-rejectRequestModal btn btn-danger"
                                           href="#rejectRequestModal">
                                            <span class="glyphicon glyphicon-remove"></span>
                                        </a>
									</td>
								</tr>
							</c:forEach>
						</tbody>
					</table>
				</div>
			</div>
			<div class="row">
				<jsp:include page="../html/footer.html"></jsp:include>
			</div>
		</div>
	</body>
</html>