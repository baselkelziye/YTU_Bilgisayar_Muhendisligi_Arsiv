<%-- 
    Document   : myannouncements
    Created on : 22.Nis.2016, 23:19:46
    Author     : must
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
    	<title>İlanlarım</title>
	</head>
	<body>
		<script>
			$(document).on("click", ".open-ChoosePacketDialog", function (e) {
				e.preventDefault();
				var _self = $(this);
				var myAnnouncementId = _self.data('id');
				$("#announcementId").val(myAnnouncementId);
				$(_self.attr('href')).modal('show');
			});

			$(document).on("click", ".complaint-message", function (e) {
				e.preventDefault();
				var _self = $(this);
				var mes = _self.data('message');
				document.getElementById("message").innerHTML = mes;
				$(_self.attr('href')).modal('show');
			});

			$(document).on("click", ".open-detail", function (e) {
				e.preventDefault();
				var _self = $(this);

				var title = _self.data('title');
				var content = _self.data('content');
				var brief = _self.data('brief');
				var publish = _self.data('publish');

				document.getElementById("title1").innerHTML = title;
				document.getElementById("content1").innerHTML = content;
				document.getElementById("publish1").innerHTML = publish;
				document.getElementById("brief1").innerHTML = brief;

				$(_self.attr('href')).modal('show');
			});
		</script>

		<div class="modal fade" id="detail" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
			<div class="modal-dialog">
				<div class="modal-content">
					<div class="modal-body">
						<h4>İlan Detayları</h4>

						<p><b>Başlık</b></p>
						<p id="title1"></p>

						<p><b>Kısa Açıklama</b></p>
						<p id="brief1"></p>

						<p><b>İçerik</b></p>
						<p id="content1"></p>

						<p><b>Şirket Adı</b></p>
						<p id="company1"></p>

						<p><b>Yayınlanma Tarihi</b></p>
						<p id="publish1"></p>

					</div>
				</div>
			</div>
		</div>

		<div class="modal fade" id="complaintMessage" tabindex="-1" role="dialog" aria-labelledby="myModalLabel3" >
			<div class="modal-dialog">
				<div class="modal-content">
					<div class="modal-body">
						<h4>İlanın Kaldırılmasına Yönelik Yönetici Mesajı:</h4>
						<br/>
						<p id="message"></p>
					</div>
					<div class="modal-footer">
						<button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
					</div>
				</div>
			</div>
		</div>

		<jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
			<div class="row">
				<div class="col-md-9">
					<c:choose>
						<c:when test="${ilanaktif eq 1 }">
							<div class = "alert alert-success">
								İlan aktif edildi.
							</div>
						</c:when>
					</c:choose>

					<h4><strong>Aktif İlanlarınız</strong></h4>
					<table class="table table-bordered">
						<thead>
							<tr>
								<th>İlan No</th>
								<th>Başlık</th>
								<th>Paket</th>
								<th>Görüntülenme Sayısı</th>
								<th>Başvuru Sayısı</th>
								<th>İşlem</th>
							</tr>
						</thead>
						<tbody>
							<c:forEach var="item" items="${announcements}">
								<c:if test="${item.state.title == 'active' }">
									<tr>
										<td>${item.id}</td>
										<td>${item.title}</td>
										<td>${item.ownerPacket.packet.title}
										<td>${item.numberOfPageViews}</td>
										<td>${fn: length(item.appStudentList)}</td>
										<td>
											<form method="post">
												<input type="hidden" name="packetId" value="${item.id}" />
												<input class="btn btn-success"
													type="submit" value="Detaya Git"
													formaction="../announcementdetail"/>
												<input class="btn btn-warning"
													type="submit" value="Yayından kaldır"
													formaction="../"/>
												<input class="btn btn-danger"
													type="submit" value="Pasif"/>
											</form>
										</td>
									</tr>
								</c:if>
							</c:forEach>
						</tbody>
					</table>

					<h4><strong>Pasif İlanlarınız</strong></h4>
						<table class="table table-bordered">
							<thead>
								<tr>
									<th>İlan No</th>
									<th>Başlık</th>
									<th>Durum</th>
									<th>Başvuru Sayısı</th>
									<th>İşlem</th>
								</tr>
							</thead>
							<tbody>
								<c:forEach var="item" items="${announcements}">
								<c:if test="${item.state.title == 'passive' }">

								<tr>
									<td>${item.id}</td>
									<td>${item.title}</td>
									<td>${item.state.title}</td>
									<td>${item.numberOfPageViews}</td>
									<td>
										<form method="post">
											<input type="hidden" name="packetId" value="${item.id}" />
											<input
												type="submit" value="Detaya Git" class="btn btn-success"
												formaction="../announcementdetail"/>
											<a data-id="${item.id }" data-toggle="modal" title="Add this item" class="open-ChoosePacketDialog btn btn-primary" href="#choosePacketDialog">
												Yayına Al
											</a>
											<input class="btn btn-danger"
												type="submit" value="Sil"
												formaction="../deleteannouncementservlet"/>
										</form>

										<div class="modal fade" id="choosePacketDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">

											<div class="modal-dialog">

											<!-- Modal content-->
											<div class="modal-content">
												<div class="modal-header">
													<button type="button" class="close" data-dismiss="modal">&times;</button>
													<h4 class="modal-title">İlanınızı Yayınlayın!</h4>
												</div>
												<div class="modal-body">
													<p>Kullanmak istediğiniz paketi seçiniz</p>

													<table class="table table-striped">
														<thead>
															<tr>
																<th>Paket adı</th>
																<th>Kalan ilan sayısı</th>
																<th>Bir ilanın yayın süresi</th>
																<th>Son Kullanma Tarihi</th>
																<th>Seç</th>
															</tr>
														</thead>
														<tbody>
															<tr><td>
															<form action="../useanannouncement" method="post">
																<c:forEach var="packet" items="${availablepackets}" varStatus="myIndex">
																	<c:if test="${packet.packet.announcementCount > packet.usedAnnouncements}">

																	</c:if>
																	<tr>
																		<td>${packet.packet.title}</td>
																		<td>${packet.packet.announcementCount - packet.usedAnnouncements}</td>
																		<td>${packet.packet.activeTime}</td>
																		<td>${packet.packet.lastDateUsed}</td>
																		<td><button class="btn btn-default" name ="ap" type="submit" value="${packet.id}">Seç</button></td>
																	</tr>
																</c:forEach>
																<input type="hidden" name="ann" id="announcementId" value="">
															</form></td></tr>
														</tbody>
													</table>
												</div>
												<div class="modal-footer">
													<p>Bir ilan aynı anda bir paketten yayında olabilir.
													<button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
												</div>
											</div>
										</div>
									</div>
								</td>
							</tr>
					</c:if>

							   </c:forEach>
						   </tbody>
					</table>


					<h4><strong>Son Kullanma Tarihi Geçen İlanlarınız</strong></h4>
					 <table class="table table-bordered">
						<thead>
							<tr>
								<th>İlan No</th>
								<th>Başlık</th>
								<th>Durum</th>
								<th>Paket(Varsa)</th>
								<th>Başvuru Sayısı</th>
								<th>İşlem</th>
							</tr>
						</thead>
						<tbody>
							   <c:forEach var="item" items="${announcements}">
									<c:if test="${item.state.title == 'expired' }">
										<tr>
											<td>${item.id}</td>
											<td>${item.title}</td>
											<td>${item.state.title}</td>
											<td>${item.ownerPacket.packet.title}
											<td>${item.numberOfPageViews}</td>
											<td>
												<form method="post">
													<input type="hidden" name="packetId" value="${item.id}" />
													<input
														type="submit" value="Detaya Git"
														formaction="../announcementdetailservlet"/>
													<input
														type="submit" value="Tekrar Yayınla"
														formaction="../"/>


												</form>
											</td>
										</tr>
									</c:if>
							   </c:forEach>
						   </tbody>
					</table>

					<h4><strong>Cezalı İlanlarınız</strong></h4>
					<table class="table table-bordered">
						<thead>
							<tr>
								<th>İlan No</th>
								<th>Başlık</th>
								<th>Durum</th>
								<th>Paket(Varsa)</th>
								<th>Şikayet Sayısı</th>
								<th>İşlem</th>
							</tr>
						</thead>
						<tbody>
							   <c:forEach var="item" items="${announcements}">
									<c:if test="${item.state.title == 'suspended' }">
										<tr>
											<td>${item.id}</td>
											<td>${item.title}</td>
											<td>${item.brief}</td>
											<td>${item.ownerPacket.packet.title}
											<td>${fn: length(item.complaintList)}</td>
											<td>
												<a  href="#detail"
													data-toggle="modal"
													data-title="${item.title}"
													data-content="${item.content}"
													data-brief="${item.brief}"
													data-publish="${item.publishDate}"
													class="open-detail btn btn-success">
													İlan Detay
												</a>
												<a  href="#complaintMessage"
													data-toggle="modal"
													class="complaint-message btn btn-warning"
													data-message="${item.complaintList[0].resultReply}">
													Ceza Sebebi
												</a>
											</td>
										</tr>
									</c:if>
							   </c:forEach>
						   </tbody>
					</table>
				</div>
			</div>
		</div>
	</body>
</html>
