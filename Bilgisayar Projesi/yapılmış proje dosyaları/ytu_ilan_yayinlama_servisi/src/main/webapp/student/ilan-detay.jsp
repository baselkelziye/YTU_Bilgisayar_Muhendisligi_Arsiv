<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>

<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-9">
		<title>İlan Detay</title>
		<jsp:include page="../html/head.html"></jsp:include>
	</head>
	<body>
        <script>
            $(document).on("click", ".open-complaintDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var code = _self.data('id');
                $("#announcementID").val(code);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".delete-complaintDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var code = _self.data('id');
                $("#announcementID2").val(code);
                $(_self.attr('href')).modal('show');
            });
        </script>

		<div class="modal fade" id="complaintDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
			<div class="modal-dialog">
				<!-- Modal content-->
				<div class="modal-content">
					<div class="modal-header">
						<button type="button" class="close" data-dismiss="modal">&times;</button>
						<h4 class="modal-title">İlanı Şikayet Et</h4>
					</div>
					<div class="modal-body">
						<p>Lütfen şikayet etme sebebinizi yazınız.</p>
                        <br/>
						<form>
							<input type="hidden" name="announcementId" id="announcementID">
                            <textarea name="complaintDescription" class="form-control" rows="3"></textarea>
                            <br/>
							<input formaction="../complaintannouncement" type="submit" class="btn btn-default" value="Gönder">
						</form>
					</div>
					<div class="modal-footer">
						<p>Asılsız şikayetler ceza puanı almanıza neden olur.</p>
                        <p>Şikayetinizi, yönetici değerlendirmeden önce geri çekebilirsiniz.</p>
						<button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
					</div>
				</div>
			</div>
		</div>

        <div class="modal fade" id="deleteComplaintDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">Şikayeti Geri Çek</h4>
                    </div>
                    <div class="modal-body">
                        <p>Şikayeti geri çekmek istediğinize emin misiniz?</p>
                        <br/>
                        <form>
                            <form>
                                <input type="hidden" name="announcementId" id="announcementID2">
                                <input formaction="../deletecomplaint" type="submit" class="btn btn-default" value="Evet">
                                <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                            </form>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <p>Onaylamanız durumunda şikayet veri tabanından silinir.</p>
                        <p>İsterseniz daha sonra tekrar şikayet edebilirsiniz.</p>
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

		<jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
			<div class="row">
				<div class="col-md-3"></div>
 				<div class="col-md-6">
                    <p><a href="../searchinitialize" class="btn btn-primary">
                        <span class="glyphicon glyphicon-arrow-left"></span> Listeye Dön
                    </a></p>
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>İlan Detay</p>
                        </div>
                        <div class="panel-body">
                            <c:choose>
                                <c:when test="${basvuruldu eq 1 }">
                                    <div class="alert alert-success">
                                        Başvurunuz gerçekleşti.
                                        Tüm başvurularınızı <a href="../myapplications">buradan</a> görebilirsiniz.
                                    </div>
                                </c:when>
                                <c:when test="${basvuruldu eq 2 }">
                                    <div class="alert alert-danger">
                                        Başvurunuz alınamadı.
                                        Lütfen daha sonra tekrar deneyin
                                    </div>
                                </c:when>
                                <c:when test="${basvuruldu eq 3 }">
                                    <div class="alert alert-warning">
                                        Başvurunuz silindi.
                                        İsterseniz yeniden başvurabilirsiniz.
                                    </div>
                                </c:when>
                                <c:when test="${basvuruldu eq 4 }">
                                    <div class="alert alert-alert">
                                        Başvurunuz silinemedi.
                                        Lütfen daha sonra tekrar deneyin.
                                    </div>
                                </c:when>
                                <c:when test="${sikayetedildi eq 1}">
                                    <div class="alert alert-success">
                                        Şikayet kaydınız oluşturuldu.
                                        Tüm şikayetlerinizi <a href="../listmycomplaints">buradan</a> görebilirsiniz.
                                    </div>
                                </c:when>
                                <c:when test="${sikayetedildi eq 2}">
                                    <div class="alert alert-success">
                                        Şikayet kaydı oluşturulurken bir hata meydane geldi.
                                        Lütfen daha sonra tekrar deneyiniz.
                                    </div>
                                </c:when>
                                <c:when test="${ilangericek eq 1}">
                                    <div class="alert alert-warning">
                                        Şikayetiniz geri çekildi.
                                        Diğer şikayetlerinizi <a href="../listmycomplaints">buradan</a> görebilirsiniz.
                                    </div>
                                </c:when>
                                <c:when test="${ilangericek eq 2}">
                                    <div class="alert alert-danger">
                                        Şikayetiniz geri çekilemedi.
                                        Lütfen daha sonra tekrar deneyiniz.
                                    </div>
                                </c:when>
                            </c:choose>
                            <table class="table table-bordered">
                                <tr>
                                    <th>Şirket Adı</th>
                                    <td>${announcement.ownerCompany.companyName}</td>
                                </tr>
                                <tr>
                                    <th>İlan Başlığı</th>
                                    <td>${announcement.title}</td>
                                </tr>
                                <tr>
                                    <th>Kısa Açıklama</th>
                                    <td>${announcement.brief}</td>
                                </tr>
                                <tr>
                                    <th colspan="2">Detay</th>
                                </tr>
                                <tr>
                                    <td colspan="2">${announcement.content }</td>
                                </tr>
                                <tr>
                                    <th>Görüntülenme Sayısı</th>
                                    <td>${announcement.numberOfPageViews}</td>
                                </tr>
                                <tr>
                                    <th>Başvuru sayısı</th>
                                    <td>${fn:length(announcement.appStudentList)}</td>
                                </tr>
                                <tr>
                                    <th>Kategori</th>
                                    <td>${announcement.category.categoryName }</td>
                                </tr>
                                <tr>
                                    <th>Yayınlanma Tarihi</th>
                                    <td><fmt:formatDate pattern="dd-MM-yyyy" value="${announcement.publishDate }"/></td>
                                </tr>
                                <tr>
                                    <td colspan="2">
                                        <c:choose>
                                            <c:when test="${user.status eq 0}">
                                                <b>Hesabınzı aktif halde getirmeden işlem yapamazsınız.</b>
                                                <b>Hesabınızı <a href="../activatestudentaccount">buradan</a> aktif hale getirebilirsiniz</b>
                                            </c:when>
                                            <c:otherwise>
                                                <form method = "post">
                                                    <input type = "hidden" name = "announcement" value = "${announcement.id}" >
                                                    <c:if test="${basvuruvar eq 1 }">
                                                        <input type="hidden" name="deleteUrl" value="student/ilan-detay.jsp">
                                                        <input disabled class="btn btn-primary disabled" type="submit" value="Başvur">
                                                        <input formaction="../deleteapplication" class="btn btn-warning active" type = "submit" value = "Başvuruyu Geri Çek">
                                                    </c:if>
                                                    <c:if test="${basvuruvar eq 2 }">
                                                        <input type = "submit" value = "İlana Başvur" formaction = "../applicationtoannouncement" class="btn btn-primary active">
                                                        <input disabled formaction="#" type = "submit" value = "Başvuruyu Geri Çek" class="btn btn-warning disabled">
                                                    </c:if>

                                                    <c:if test="${announcement.properComplaint eq true}">
                                                        <c:choose>
                                                            <c:when test="${sikayetvar eq 2}">
                                                                <a href="#complaintDialog"
                                                                   data-toggle="modal"
                                                                   class="open-complaintDialog btn btn-danger"
                                                                   data-id="${announcement.id}">Şikayet Et</a>
                                                            </c:when>
                                                            <c:otherwise>
                                                                <a href="#deleteComplaintDialog"
                                                                   data-toggle="modal"
                                                                   class="delete-complaintDialog btn btn-warning"
                                                                   data-id="${announcement.id}">Şikayeti Geri Çek</a>
                                                            </c:otherwise>
                                                        </c:choose>
                                                    </c:if>
                                                </form>
                                            </c:otherwise>
                                        </c:choose>
                                    </td>
                                </tr>
                            </table>
                        </div>
                    </div>
 				</div>
 			</div>
		</div>
	</body>
</html>