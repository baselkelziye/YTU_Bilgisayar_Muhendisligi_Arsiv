<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-9">
		<title>CV Düzenle</title>
		<jsp:include page="../html/head.html"></jsp:include>
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
	  	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
	  	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

        <script>
            $(document).ready(function(){
                $('[data-toggle="popover"]').popover();
            });
        </script>
	</head>
	<body>
        <script>
            $(document).on("click", ".open-addComWay", function (e) {
                e.preventDefault();
                var _self = $(this);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-deleteCommWay", function (e) {
                e.preventDefault();
                var _self = $(this);

                var type = _self.data('type');
                $("#type2").val(type);
                var value = _self.data('value');
                $("#value2").val(value);

                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-updateCommWay", function (e) {
                e.preventDefault();
                var _self = $(this);

                var type = _self.data('type');
                $("#type3").val(type);
                $("#type4").val(type);
                var value = _self.data('value');
                $("#value3").val(value);
                $("#value4").val(value);

                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-addEducation", function (e) {
                e.preventDefault();
                var _self = $(this);
                $(_self.attr('href')).modal('show');
            });
        </script>

        <div class="modal fade" id="addComWay" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>Yeni İletişim Bilgisi Ekleyin</p>
                        <form action="../addcommwaystudent">
                            <div class="form-group">
                                <label for="commTitle">İletişim Tipi</label>
                                <input type="text" class="form-control" id="commTitle" name="commTitle" placeholder="telefon,mail,linkedin vb">
                            </div>
                            <div class="form-group">
                                <label for="commValue">Değeri</label>
                                <input type="text" class="form-control" id="commValue" name="commValue" placeholder="adres/numara">
                            </div>
                            <button type="submit" class="btn btn-default">Kaydet</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="addEducation" tabindex="-1" role="dialog" aria-labelledby="myModalLabel3" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>Yeni Eğitim Bilgisi Ekleyin</p>
                        <form action="../addeducationinfo">
                            <div class="form-group">
                                <label for="school">Okul</label>
                                <input type="text" class="form-control" id="school" name="school">
                            </div>
                            <div class="form-group">
                                <label for="school">Bölüm</label>
                                <input type="text" class="form-control" id="department" name="department">
                            </div>
                            <div class="form-group">
                                <label>Derecesi</label>
                                <select name="degree" class="form-control" id="degree">
                                    <option value="Lise">Lise</option>
                                    <option value="Ön Lisans">Ön Lisans</option>
                                    <option value="Lisans">Lisans</option>
                                    <option value="Yüksek Lisans">Yüksek Lisans</option>
                                    <option value="Doktora">Doktora</option>
                                </select>
                            </div>
                            <div class="form-group">
                                <label for="start">Başlangıç Yılı</label>
                                <input type="text" class="form-control" id="start" name="start">
                            </div>
                            <div class="form-group">
                                <label for="end">Bitiş Yılı (Mezun Değilseniz 0 giriniz)</label>
                                <input type="text" class="form-control" id="end" name="end">
                            </div>
                            <button type="submit" class="btn btn-default">Kaydet</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="deleteCommWay" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>Silmek istediğinize emin misiniz?</p>
                        <form>
                            <input type="hidden" name="type" id="type2">
                            <input type="hidden" name="value" id="value2">
                            <input formaction="../deletecommwaystudent" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                    <div class="modal-footer">
                        <button type="button" class="btn btn-default" data-dismiss="modal">Kapat</button>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="updateCommWay" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" >
            <div class="modal-dialog">
                <div class="modal-content">
                    <div class="modal-body">
                        <p>İletişim Bilgisini Düzenleyin</p>
                        <form action="../updatestudentcommway" method="post">
                            <div class="form-group">
                                <label for="commTitle">İletişim Tipi</label>
                                <input type="text" class="form-control" id="type3" name="type" placeholder="telefon,mail,linkedin vb">
                            </div>
                            <div class="form-group">
                                <label for="commValue">Değeri</label>
                                <input type="text" class="form-control" id="value3" name="value" placeholder="adres/numara">
                            </div>
                            <input type="hidden" name="oldType" id="type4">
                            <input type="hidden" name="oldValue" id="value4">
                            <button type="submit" class="btn btn-default">Güncelle</button>
                        </form>
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
					<div class="col-md-4">
                        <div class="panel panel-primary">
                            <div class="panel-heading">
                                <p>İletişim Bilgileri</p>
                            </div>
                            <div class="panel-body">
                                <c:choose>
                                    <c:when test="${iletisim eq 1 }">
                                        <div class="alert alert-success">
                                            Yeni iletişim tipi eklendi.
                                        </div>
                                    </c:when>
                                    <c:when test="${iletisim eq 2 }">
                                        <div class="alert alert-danger">
                                            Eklenirken bir hata meydana geldi.
                                        </div>
                                    </c:when>
                                    <c:when test="${iletisim eq 3 }">
                                        <div class="alert alert-success">
                                            İletişim bilginiz silindi.
                                        </div>
                                    </c:when>
                                    <c:when test="${iletisim eq 4 }">
                                        <div class="alert alert-danger">
                                            Silinirken bir hata meydana geldi.
                                        </div>
                                    </c:when>
                                    <c:when test="${iletisim eq 5 }">
                                        <div class="alert alert-success">
                                            İletişim bilginiz güncellendi.
                                        </div>
                                    </c:when>
                                    <c:when test="${iletisim eq 6 }">
                                        <div class="alert alert-danger">
                                            Güncellenirken bir hata meydana geldi.
                                        </div>
                                    </c:when>
                                </c:choose>
                                <table class="table table-stripped">
                                    <thead>
                                    <tr>
                                        <th>İletişim Tipi</th>
                                        <th>Değeri</th>
                                        <th>İşlem</th>
                                    </tr>
                                    </thead>
                                    <tbody>
                                    <c:forEach var="item" items="${commWays}">
                                        <tr>
                                            <td>${item.pk.commType }</td>
                                            <td>
                                                <c:choose>
                                                    <c:when test="${fn:length(item.pk.commValue) < 15}">
                                                        ${item.pk.commValue }
                                                    </c:when>
                                                    <c:otherwise>
                                                        ${fn:substring(item.pk.commValue, 0, 15)}...
                                                        <a href="#" data-toggle="popover" data-placement="left"
                                                           title="Değeri:" data-content="${item.pk.commValue}">
                                                            <span class="glyphicon glyphicon-info-sign "></span>
                                                        </a>
                                                    </c:otherwise>
                                                </c:choose>
                                            </td>
                                            <td>
                                                <a  href="#updateCommWay"
                                                    toogle="modal"
                                                    data-value="${item.pk.commValue}"
                                                    data-type="${item.pk.commType}"
                                                    class="open-updateCommWay btn btn-primary"
                                                    title="Düzenle">
                                                    <span class="glyphicon glyphicon-pencil"></span>
                                                </a>
                                                <a  href="#deleteCommWay"
                                                    toogle="modal"
                                                    data-value="${item.pk.commValue}"
                                                    data-type="${item.pk.commType}"
                                                    class="open-deleteCommWay btn btn-danger"
                                                    title="Sil">
                                                    <span class="glyphicon glyphicon-trash"></span>
                                                </a>
                                            </td>
                                        </tr>
                                    </c:forEach>
                                    </tbody>
                                </table>
                            </div>
                            <div class="modal-footer">
                                <a  href="#addComWay"
                                    toogle="modal"
                                    class="open-addComWay btn btn-success"
                                    title="Yeni İletişim Bilgisi Ekle">
                                    <span class="glyphicon glyphicon-plus"></span> Ekle
                                </a>
                            </div>
                        </div>
                    </div>
					<div class="col-md-3">
                        <div class="panel panel-primary">
                            <div class="panel-heading">
                                <p>Kişisel Bilgiler</p>
                            </div>
                            <div class="panel-body">
                                <c:choose>
                                    <c:when test="${personal eq 1}">
                                        <div class="alert alert-success">
                                            Bilginiz güncellendi.
                                        </div>
                                    </c:when>
                                    <c:when test="${personal eq 2}">
                                        <div class="alert alert-danger">
                                            Bir hata meydana geldi.
                                        </div>
                                    </c:when>
                                </c:choose>
                                <form method="post" action="../updatestudentuser">
                                    <div class="form-group">
                                        <label for="name">Adınız</label>
                                        <input type="text" class="form-control" name="name" value="${user.name}" id="name">
                                    </div>
                                    <div class="form-group">
                                        <label for="surname">Soyadınız</label>
                                        <input type="text" class="form-control" name="surname" value="${user.surname}" id="surname">
                                    </div>
                                    <div class="form-group">
                                        <label for="birthdate">Doğum Tarihiniz</label>
                                        <input type="text" class="form-control" name="birthdate" value="${user.birthDate}" id="birthdate">
                                    </div>
                                    <button type="submit" class="btn btn-success">Güncelle</button>
                                </form>
                            </div>
                        </div>
					</div>
                    <div class="col-md-5">
                        <div class="panel panel-primary">
                            <div class="panel-heading">
                                <p>Eğitim Bilgileriniz</p>
                            </div>
                            <div class="panel-body">
                                <c:choose>
                                    <c:when test="${egitim eq 1}">
                                        <div class="alert alert-success">
                                            Eğitim bilgisi eklendi.
                                        </div>
                                    </c:when>
                                    <c:when test="${egitim eq 2}">
                                        <div class="alert alert-danger">
                                            Bir hata meydana geldi.
                                        </div>
                                    </c:when>
                                </c:choose>
                                <table class="table table-stripped">
                                    <thead>
                                        <th>Okul</th>
                                        <th>Derece</th>
                                        <th>Tarih</th>
                                        <th>İşlem</th>
                                    </thead>
                                    <tbody>
                                        <c:if test="${fn:length(educationList) eq 0}">
                                            <p>Henüz kayıt girilmemiş.</p>
                                        </c:if>
                                        <c:forEach var="item" items="${educationList}">
                                        <tr>
                                            <td>
                                                ${fn:substring(item.school, 0, 20)}...
                                                <a href="#" data-toggle="popover" data-placement="left"
                                                   title="Okul Bilgisi:" data-content="Okul:${item.school} Bölüm:${item.department}">
                                                    <span class="glyphicon glyphicon-info-sign "></span>
                                                </a>
                                            </td>
                                            <td>${item.degree}</td>
                                            <td>
                                                    ${item.startDate} -
                                                <c:choose>
                                                    <c:when test="${item.endDate eq 0}">
                                                        ?
                                                    </c:when>
                                                    <c:otherwise>
                                                        ${item.endDate}
                                                    </c:otherwise>
                                                </c:choose>
                                            </td>
                                            <td>
                                                <a  href="#updateEducation"
                                                    toogle="modal"
                                                    data-school="${item.school}"
                                                    data-start="${item.startDate}"
                                                    date-end="${item.endDate}"
                                                    class="open-updateEducation btn btn-primary"
                                                    title="Düzenle">
                                                    <span class="glyphicon glyphicon-pencil"></span>
                                                </a>
                                                <a  href="#deleteEducation"
                                                    toogle="modal"
                                                    data-id="${item.id}"
                                                    class="open-deleteEducation btn btn-danger"
                                                    title="Sil">
                                                    <span class="glyphicon glyphicon-trash"></span>
                                                </a>
                                            </td>
                                        </tr>
                                    </c:forEach>
                                    </tbody>
                                </table>
                            </div>
                            <div class="panel-footer">
                                <div class="modal-footer">
                                    <a  href="#addEducation"
                                        toogle="modal"
                                        class="open-addEducation btn btn-success"
                                        title="Yeni Eğitim Bilgisi Ekle">
                                        <span class="glyphicon glyphicon-plus"></span> Ekle
                                    </a>
                                </div>
                            </div>
                        </div>
                    </div>
				</div>
		</div>
	</body>
</html>