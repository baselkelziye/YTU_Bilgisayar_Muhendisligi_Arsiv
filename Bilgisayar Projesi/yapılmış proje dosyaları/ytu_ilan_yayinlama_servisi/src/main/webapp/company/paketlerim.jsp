<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>

<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
		<jsp:include page="html/head.html"/>
		<title>Paketlerim</title>
        <script>
            $(document).ready(function(){
                $('[data-toggle="popover"]').popover();
            });

            $(document).on("click", ".open-sendRequestModal", function (e) {
                e.preventDefault();
                var _self = $(this);
                var packetID = _self.data('id');
                $("#packetID").val(packetID);
                $(_self.attr('href')).modal('show');
            });
        </script>
	</head>
	<body>
        <div class="modal fade" id="sendRequestModal" role="dialog">
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">2.Ödeme Bilgisi Gir</h4>
                    </div>
                    <div class="modal-body">
                        <p>Yapılan bağış ile ilgili bilgileri giriniz.</p>
                        <p>Fatura/ödeme bilgisine ait görüntü veya pdf ekleyiniz.</p>
                        <form method="post" action="../seconddonationrequest" enctype="multipart/form-data">
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
                        <p>Bu son ödeme hakkınızdır.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

		<jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
			<div class="row">
                <div class="col-md-1"></div>
				<div class="col-md-3">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Arama Kriterleriniz</p>
                        </div>
                        <div class="panel-body">
                            <form method="post" action="../searchmypackets">
                                <div class="form-group">
                                    <label for="state">Durumu</label>
                                    <select class="form-control" id="state" name="packetState">
                                        <c:forEach var="item" items="${packetStates}">
                                            <option value="${item.id}">
                                                <c:out value="${item.title}"/>
                                            </option>
                                        </c:forEach>
                                    </select>
                                </div>
                                <button type="submit" class="btn btn-success">Getir</button>
                            </form>
                        </div>
                    </div>
                </div>
				<div class="col-md-8">
                    <c:if test="${fn:length(packets) eq 0}">
                        <p>Sonuç yok.</p>
                        <p>Yan paneli kullanarak arama yapabilirsiniz.</p>
                    </c:if>
                    <c:choose>
                        <c:when test="${ikinciistek eq 1}">
                            <div class="alert alert-success">
                                İkinci istek gönderildi
                            </div>
                        </c:when>
                        <c:when test="${ikinciistek eq 2}">
                            <div class="alert alert-success">
                                Bir hata meydana geldi.
                            </div>
                        </c:when>
                    </c:choose>
					<table class="table table-hover">
						<thead>
							<tr>
								<th>Durumu
                                    <a href="../ordermypackets?condition=announcement_packet_state&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../ordermypackets?condition=announcement_packet_state&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
								<th>Paket Başlığı</th>
								<th>Kullanılan/Kalan</th>
								<th>Tarih
                                    <a href="../ordermypackets?condition=time_to_approved&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../ordermypackets?condition=time_to_approved&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
								<th>SKT <a href="#" title="Son Kullanım Tarihi"><span class="glyphicon glyphicon-question-sign"></span></a>
                                    <a href="../ordermypackets?condition=time_to_expired&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../ordermypackets?condition=time_to_expired&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
								<th>İşlem</th>
							</tr>
						</thead>
						<tbody>
							<c:forEach var="item" items="${packets}">
								<tr>
									<td>${item.state.title}</td>
									<td>${item.packet.title}</td>
									<td align="right">${item.usedAnnouncements}/${item.packet.announcementCount - item.usedAnnouncements}</td>
									<td align="right"><fmt:formatDate pattern="dd-MM-yyyy" value="${item.timeToApproved}"/></td>
									<td align="right"><fmt:formatDate pattern="dd-MM-yyyy" value="${item.timeToExpired}"/></td>
                                    <td>
                                        <c:if test="${item.state.id eq 4}">
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               class="btn btn-success" title="Açıklama:" data-content="${item.dauDescription}">
                                                <span class="glyphicon glyphicon-info-sign"></span>
                                            </a>
                                            <a data-id="${item.id }"
                                               data-toggle="modal"
                                               title="Bağış Yaptım"
                                               class="open-sendRequestModal btn btn-primary"
                                               href="#sendRequestModal">
                                                <span class="glyphicon glyphicon-repeat"></span>
                                            </a>
                                        </c:if>
                                        <c:if test="${item.state.id eq 5}">
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               class="btn btn-success" title="Açıklama:"
                                               data-content="İlk açıklama: ${item.dauDescription}
                                                İkinci Açıklama: ${item.secondDauDescription}">
                                                <span class="glyphicon glyphicon-info-sign"></span>
                                            </a>
                                        </c:if>
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