<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-9">
		<title>Muhasebe Kayıtları</title>
        <jsp:include page="html/head.html"/>
		<link rel="stylesheet" href="//code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
		<script src="https://code.jquery.com/jquery-1.12.4.js"></script>
		<script src="../js/datePicker.js" charset="UTF-8"></script>
		<script>
			$( function() {
				var dateFormat = "dd/mm/yy",
						from = $( "#from" )
								.datepicker({
									defaultDate: "+1w",
									changeMonth: true,
									numberOfMonths: 1
								})
								.on( "change", function() {
									to.datepicker( "option", "minDate", getDate( this ) );
								}),
						to = $( "#to" ).datepicker({
							defaultDate: "+1w",
							changeMonth: true,
							numberOfMonths: 1
						})
								.on( "change", function() {
									from.datepicker( "option", "maxDate", getDate( this ) );
								});

				function getDate( element ) {
					var date;
					try {
						date = $.datepicker.parseDate( dateFormat, element.value );
					} catch( error ) {
						date = null;
					}

					return date;
				}
			} );
		</script>
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
                            <p>Arama Yapın</p>
                        </div>
                        <div class="panel-body">
                            <form action="../filterbalance">
                                <div class="form-group">
                                    <label for="from">Başlangıç Tarihi</label>
                                    <input type="text" id="from" name="from" class="form-control">
                                </div>
                                <div class="form-group">
                                    <label for="to">Bitiş Tarihi</label>
                                    <input type="text" id="to" name="to" class="form-control">
                                </div>
                                <div class="form-group">
                                    <label for="dau">BKB Seç</label>
                                    <select name="department" id="dau" class="form-control">
                                        <c:forEach var="item" items="${alldau}">
                                            <c:choose>
                                                <c:when test="${item.unitName eq 'Tüm Birimler'}">
                                                    <option selected value="${item.unitName}">
                                                        <c:out value="${item.unitName}"/>
                                                    </option>
                                                </c:when>
                                                <c:otherwise>
                                                    <option value="${item.unitName}">
                                                        <c:out value="${item.unitName}"/>
                                                    </option>
                                                </c:otherwise>
                                            </c:choose>
                                        </c:forEach>
                                    </select>
                                </div>
                                <button type="submit" class="btn btn-success">Kayıtları Getir</button>
                            </form>
                        </div>
                    </div>
				</div>
				<div class="col-md-7">
                    <c:if test="${fn:length(dau) eq 0}">
                        <p>Lütfen yan menüden seçim yapınız.</p>
                    </c:if>
					<h4>Bakiye Miktarları (TL)</h4>
					<table class="table table-stripped">
                        <c:forEach var="item" items="${dau}">
                            <c:if test="${item.unitName ne 'Tüm Birimler'}">
                                <tr>
                                    <th>${item.unitName}</th>
                                    <td align="right">${item.balance}</td>
                                <tr>
                            </c:if>
                        </c:forEach>
					</table>

                    <p><b>İşlem Kayıtları</b> <i>${fn:length(accounting)} kayıt</i></p>
                    <table class="table table-hover">
                        <thead>
                        <tr>
                            <th>İşlem tarihi
                                <a href="../accountingorder?condition=date_time&type=asc" title="Artan Sırala">
                                    <span class="glyphicon glyphicon-arrow-up"></span>
                                </a>
                                <a href="../accountingorder?condition=date_time&type=desc" title="Azalan Sırala">
                                    <span class="glyphicon glyphicon-arrow-down"></span>
                                </a>
                            </th>
                            <th>Açıklama
                                <a href="../accountingorder?condition=description&type=asc" title="Artan Sırala">
                                    <span class="glyphicon glyphicon-arrow-up"></span>
                                </a>
                                <a href="../accountingorder?condition=description&type=desc" title="Azalan Sırala">
                                    <span class="glyphicon glyphicon-arrow-down"></span>
                                </a>
                            </th>
                            <th>Birim Adı
                                <a href="../accountingorder?condition=unit_name&type=asc" title="Artan Sırala">
                                    <span class="glyphicon glyphicon-arrow-up"></span>
                                </a>
                                <a href="../accountingorder?condition=unit_name&type=desc" title="Azalan Sırala">
                                    <span class="glyphicon glyphicon-arrow-down"></span>
                                </a>
                            </th>
                            <th>Kullanıcı
                                <a href="../accountingorder?condition=user_name&type=asc" title="Artan Sırala">
                                    <span class="glyphicon glyphicon-arrow-up"></span>
                                </a>
                                <a href="../accountingorder?condition=user_name&type=desc" title="Azalan Sırala">
                                    <span class="glyphicon glyphicon-arrow-down"></span>
                                </a>
                            </th>
                            <th>Miktar (TL)
                                <a href="../accountingorder?condition=amount&type=asc" title="Artan Sırala">
                                    <span class="glyphicon glyphicon-arrow-up"></span>
                                </a>
                                <a href="../accountingorder?condition=amount&type=desc" title="Azalan Sırala">
                                    <span class="glyphicon glyphicon-arrow-down"></span>
                                </a>
                            </th>
                        </tr>
                        </thead>
                        <tbody>
                        <c:forEach var="item" items="${accounting }">
                            <tr>
                                <td><fmt:formatDate pattern="dd-MM-yyy" value="${item.accountingPK.dateTime}"/></td>
                                <td>
                                    <c:choose>
                                        <c:when test="${fn:length(item.description) < 20}">
                                            ${item.description}
                                        </c:when>
                                        <c:otherwise>
                                            ${fn:substring(item.description, 0, 20)}...
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               title="Açıklama:${item.description}" data-content="${item.description}">
                                                <span class="glyphicon glyphicon-info-sign "></span>
                                            </a>
                                        </c:otherwise>
                                    </c:choose>
                                </td>
                                <td>${item.dauUser.dau.unitName }</td>
                                <td>${item.dauUser.userName }</td>
                                <td align="right">${item.amount}</td>
                            </tr>
                        </c:forEach>
                        </tbody>
                    </table>
				</div>
            </div>
        </div>
        <jsp:include page="html/footer.html"/>
	</body>
</html>