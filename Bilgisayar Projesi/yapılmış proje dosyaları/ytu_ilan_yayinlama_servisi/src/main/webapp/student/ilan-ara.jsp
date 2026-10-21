<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
<html>
	<head>
		<jsp:include page="html/head.html"></jsp:include>
		<title>İlan Ara</title>
        <style>
            .slow .toggle-group { transition: left 0.7s; -webkit-transition: left 0.7s; }
        </style>

        <script>
            $(document).ready(function(){
                $('[data-toggle="popover"]').popover();
            });
        </script>
	</head>
	<body>
		<jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
			<div class="row">
                <div class="col-md-1"></div>
				<div class="col-md-3">
					<div class="panel panel-primary">
						<div class="panel-heading">
							<p>İlan Ara</p>
						</div>
						<div class="panel-body">
                            <form action="../searchannouncement">
                                <div class="form-group">
                                    <label>İlan Kategorisi</label>
                                    <select name="category" class="form-control">
                                        <c:forEach var="item" items="${categoryList}">
                                            <c:if test="${item.id ne 0 }">
                                                <c:if test="${item.parentCategory eq 0}">
                                                    <option value="${item.id}">
                                                        <b><c:out value="${item.categoryName}"/></b>
                                                    </option>
                                                    <c:forEach var="childItem" items="${item.children}">
                                                        <option value="${childItem.id}">
                                                            <c:out value="----${childItem.categoryName}"/>
                                                        </option>
                                                    </c:forEach>
                                                </c:if>
                                            </c:if>
                                        </c:forEach>
                                    </select>
                                </div>
                                <div class="form-group">
                                    <label>İlan Tipi</label>
                                    <select name="type" class="form-control">
                                        <c:forEach var="item" items="${annType}">
                                            <option value="${item.id}">
                                                <c:out value="${item.title}"/>
                                            </option>
                                        </c:forEach>
                                    </select>
                                </div>
                                <div class="form-group">
                                    <label>İlanın Dili</label>
                                    <select name="language" class="form-control" id="language">
                                        <option value="alllanguages">Tüm Diller</option>
                                        <option value="türkçe">Türkçe</option>
                                        <option value="ingilizce">İngilizce</option>
                                    </select>
                                </div>
                                <div class="form-group">
                                    <label for="keyword">Anahtar Kelimeler</label>
                                    <h5>Kelimeler arasında virgül bırakın.(Ör: java,hibernate,css)</h5>
                                    <input type="text" name="keywords" placeholder="Anahtar Kelimeler" class="form-control" id="keyword">

                                </div>

                                <button type="submit" class="btn btn-success">Ara</button>
                            </form>
                        </div>
					</div>
				</div>
                <div class="col-md-8">
                    <a href="../announcementstostudent" class="btn btn-primary">Tüm İlanları Getir</a>
                    <c:choose>
                        <c:when test="${fn:length(announcements) eq 0}">
                            <h4>Gösterilecek ilan yok!</h4>
                            <h4>Yan menüden seçim yapabilirsiniz.</h4>
                        </c:when>
                        <c:otherwise>
                            <table class="table table-stripped">
                                <thead>
                                <tr>
                                    <th>İlan Başlığı
                                        <a href="../announcementorder?condition=title&type=asc" title="Artan Sırala">
                                            <span class="glyphicon glyphicon-arrow-up"></span>
                                        </a>
                                        <a href="../announcementorder?condition=title&type=desc" title="Azalan Sırala">
                                            <span class="glyphicon glyphicon-arrow-down"></span>
                                        </a>
                                    </th>
                                    <th>Kısa Açıklama</th>
                                    <th>İlan Tipi
                                        <a href="../announcementorder?condition=announcement_type&type=asc" title="Artan Sırala">
                                            <span class="glyphicon glyphicon-arrow-up"></span>
                                        </a>
                                        <a href="../announcementorder?condition=announcement_type&type=desc" title="Azalan Sırala">
                                            <span class="glyphicon glyphicon-arrow-down"></span>
                                        </a>
                                    </th>
                                    <th>Yayınlayan
                                        <a href="../announcementorder?condition=owner_company&type=asc" title="Artan Sırala">
                                            <span class="glyphicon glyphicon-arrow-up"></span>
                                        </a>
                                        <a href="../announcementorder?condition=owner_company&type=desc" title="Azalan Sırala">
                                            <span class="glyphicon glyphicon-arrow-down"></span>
                                        </a>
                                    </th>
                                    <th>Yayın Tarihi
                                        <a href="../announcementorder?condition=publish_date&type=asc" title="Artan Sırala">
                                            <span class="glyphicon glyphicon-arrow-up"></span>
                                        </a>
                                        <a href="../announcementorder?condition=publish_date&type=desc" title="Azalan Sırala">
                                            <span class="glyphicon glyphicon-arrow-down"></span>
                                        </a>
                                    </th>
                                    <th>İşlem</th>
                                </tr>
                                </thead>
                                <tbody>

                                <c:forEach var="item" items="${announcements}">
                                    <tr>
                                        <td>${item.title}</td>
                                        <td>
                                            ${fn:substring(item.brief, 0, 15)}...
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               title="Açıklama" data-content="${item.brief}">
                                                <span class="glyphicon glyphicon-info-sign "></span>
                                            </a>
                                        </td>
                                        <td>${item.announcementType.title}</td>
                                        <td>${item.ownerCompany.companyName}</td>
                                        <td><fmt:formatDate pattern="dd-MM-yyy" value="${item.publishDate}"/></td>
                                        <td>
                                            <form action = "../announcementdetailtostudent" method = "post">
                                                <input type="hidden" name="announcement" value="${item.id}"/>
                                                <input type="submit" class="btn btn-success" value="Detay"/>
                                            </form>
                                        </td>
                                    </tr>
                                </c:forEach>
                                </tbody>
                            </table>
                        </c:otherwise>
                    </c:choose>
                </div>
			</div>
		</div>
	</body>
</html>