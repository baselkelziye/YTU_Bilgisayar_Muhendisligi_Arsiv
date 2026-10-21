<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
    	<title>İlanlarım</title>
	</head>
	<body>
		<jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
            <div class="col-md-2"></div>
			<div class="row">
				<div class="col-md-8">
				<a href="../myactiveannouncements" class="btn btn-info">
					<span class="glyphicon glyphicon-arrow-left"></span> Aktif İlanlarım
				</a>
				
				<h4>${announcement.id} nolu ilanınızın detayları</h4>
				
				<table class="table table-stripped">
					<tr>
						<th>İlan No:</th>
						<td>${announcement.id}</td>
					</tr>
					<tr>
						<th>İlan Başlığı:</th>
						<td>${announcement.title}</td>
					</tr>
					<tr>
						<th>Kısa Açıklama:</th>
						<td>${announcement.brief}</td>
					</tr>
					<tr>
						<th>Açıklama:</th>
						<td>${announcement.content}</td>
					</tr>
					<tr>
						<th>Kategori</th>
						<td>${announcement.category.categoryName }</td>
					</tr>
					<tr>
						<th>İlanın Dili</th>
						<td>${announcement.announcementLanguage}</td>
					</tr>
					<tr>
                        <th>Yayınlanma Tarihi</th>
                        <td><fmt:formatDate pattern="dd-MM-yyyy" value="${announcement.publishDate}"/></td>
                    </tr>
                    <tr>
                        <th>Yayın Sonu Tarihi</th>
                        <td><fmt:formatDate pattern="dd-MM-yyyy" value="${announcement.expiredDate}"/></td>
                    </tr>
					<tr>
						<td><button class="btn btn-default" name ="appList" type="submit">İlanı Düzenle</button></td>
					<tr>
				</table>
				
				<h4><strong>Yapılan Başvurular</strong></h4>
				<table class="table table-hover">
					<thead>
						<tr>
							<th>Ad</th>
							<th>Soyad</th>
							<th>Bölüm</th>
                            <th>Başvuru Zamanı</th>
							<th>İşlem</th>
						</tr>							
					</thead>
					<tbody>
						<c:forEach var="item" items="${announcement.appStudentList }">
							<tr>
								<td>${item.pk.user.name }</td>
								<td>${item.pk.user.surname }</td>
								<td>${item.pk.user.department.name }</td>
                                <td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.timeToApplication}"/></td>
								<td>
                                    <a href="../displaystudentcv?username=${item.pk.user.userName}"
                                       class="btn btn-info"
                                       target="_blank">CV Görüntüle</a>
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
	