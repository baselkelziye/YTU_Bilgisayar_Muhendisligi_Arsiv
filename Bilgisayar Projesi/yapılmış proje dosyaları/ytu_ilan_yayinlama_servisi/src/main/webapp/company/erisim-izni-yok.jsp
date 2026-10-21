<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="../css/bootstrap.css">
        <jsp:include page="html/head.html"/>
		<title>İlanlarım</title>
	</head>
	<body>
		<jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
			<div class="row">
				<div class="col-md-3"><jsp:include page="html/menu.html"/></div>
				<div class="col-md-8">
					Bu sayfaya erişim izniniz bulunmamaktadır.
				</div>
			</div>
			<div class="row">
				<jsp:include page="../html/footer.html"></jsp:include>
			</div>
		</div>
	</body>
</html>