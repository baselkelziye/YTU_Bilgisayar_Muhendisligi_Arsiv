<%@ page language="java" contentType="text/html; charset=ISO-8859-9"
    pageEncoding="ISO-8859-9"%>  
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>

<!DOCTYPE html>
<html>
	<head>
		<jsp:include page="html/head.html"></jsp:include>
		<link rel="stylesheet" type="text/css" href="../css/bootstrap.css">
		<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-9">
        <link rel="stylesheet" href="//code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
        <script src="https://code.jquery.com/jquery-1.12.4.js"></script>
        <script src="../js/datePicker.js" charset="UTF-8"></script>
		<title>Hesap İşlem Geçmişi</title>

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
	</head>
	<body>
		<jsp:include page="html/menu.html"></jsp:include>
		<div class="jumbotron container-fluid">
			<div class="row">
				<div class="col-md-1"></div>
                <div class="col-md-3">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Arama Yapın</p>
                        </div>
                        <div class="panel-body">
                            <form action="../searchmyaccounting" method="post">
								<div class="form-group">
									<label for="dau">Kullanıcı Seç</label>
									<select name="username" id="dau" class="form-control">
										<c:forEach var="item" items="${userList}">
											<option value="${item.userName}">
												<c:out value="${item.userName}"/>
											</option>
										</c:forEach>
                                        <option selected value="all">
                                            <c:out value="Tüm Kullanıcılar"/>
                                        </option>
									</select>
								</div>
                                <div class="form-group">
                                    <label>Kayıt Tipi</label>
                                    <br/><input type="radio" name="type" value="spent"> Harcama
                                    <br/><input type="radio" name="type" value="accept"> Bağış Kabul
                                    <br/><input type="radio" name="type" checked value="all"> Tümü
                                </div>
                                <div class="form-group">
                                    <label for="from">Başlangıç Tarihi</label>
                                    <input type="text" id="from" name="from" class="form-control">
                                </div>
                                <div class="form-group">
                                    <label for="to">Bitiş Tarihi</label>
                                    <input type="text" id="to" name="to" class="form-control">
                                </div>
                                <button type="submit" class="btn btn-success">Ara</button>
                            </form>
                        </div>
                    </div>
                </div>
				<div class="col-md-6">
					<h4>BKB bakiyesi: ${user.dau.balance}</h4>
                    <c:if test="${fn:length(accounting) eq 0}">
                        <p>Kayıtları görmek için paneli kullanın</p>
                    </c:if>
					
					<table class="table table-hover">
						<thead>
							<tr>
								<th>Kullanıcı
                                    <a href="../myaccountingorder?condition=user_name&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../myaccountingorder?condition=user_name&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
                                <th>Açıklama</th>
								<th>İşlem tarihi
                                    <a href="../myaccountingorder?condition=date_time&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../myaccountingorder?condition=date_time&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
								<th>Miktar
                                    <a href="../myaccountingorder?condition=amount&type=asc" title="Artan Sırala">
                                        <span class="glyphicon glyphicon-arrow-up"></span>
                                    </a>
                                    <a href="../myaccountingorder?condition=amount&type=desc" title="Azalan Sırala">
                                        <span class="glyphicon glyphicon-arrow-down"></span>
                                    </a>
                                </th>
							</tr>	
						</thead>
						<tbody>
							<c:forEach var="item" items="${accounting }">
								<tr>
									<td>${item.dauUser.userName }</td>
                                    <td>
                                        <c:choose>
                                            <c:when test="${fn:length(item.description) < 30}">
                                                ${item.description}
                                            </c:when>
                                            <c:otherwise>
                                                ${fn:substring(item.description, 0, 30)}...
                                                <a href="#" data-toggle="popover" data-placement="left"
                                                   title="Açıklama:${item.description}" data-content="${item.description}">
                                                    <span class="glyphicon glyphicon-info-sign "></span>
                                                </a>
                                            </c:otherwise>
                                        </c:choose>
                                    </td>
									<td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.accountingPK.dateTime}"/></td>
									<td align="right">${item.amount}</td>
								</tr>
							</c:forEach>
						</tbody>
					</table>
				</div>
			</div>
		</div>
	</body>
</html>