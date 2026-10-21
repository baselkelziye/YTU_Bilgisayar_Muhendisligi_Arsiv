<%-- 
    Document   : createannouncementpacket
    Created on : 17.Nis.2016, 15:33:19
    Author     : must
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
        <script src="https://code.jquery.com/jquery-1.12.4.js"></script>
        <link rel="stylesheet" href="//code.jquery.com/ui/1.12.1/themes/base/jquery-ui.css">
        <title>Paket Oluştur</title>
        <script src="../js/datePicker.js" charset="UTF-8"></script>
        <script>
            $( function() {
                var dateFormat = "dd/mm/yy",
                        last_date_used = $( "#last_date_used" )
                                .datepicker({
                                    defaultDate: "+1w",
                                    changeMonth: true,
                                    numberOfMonths: 1
                                })
                                .on( "change", function() {
                                    to.datepicker( "option", "minDate", getDate( this ) );
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
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-3">
                    <div class="text-centers">
                        <c:choose>
                            <c:when test="${olusturuldu eq 1}">
                                <div class="alert alert-success">
                                    <strong>Başarılı!</strong> Paket pasif olarak oluşturuldu.
                                    Paketi <a href="../displaypackets">buradan</a> aktif hale getirebilirsiniz.
                                </div>
                            </c:when>
                            <c:when test="${olusturuldu eq 2}">
                                <div class ="alert alert-danger">
                                    <strong>Başarısız</strong>Bir hata meydana geldi. Lütfen daha sonra tekrar deneyiniz.
                                </div>
                            </c:when>
                        </c:choose>

                        <form method="post" action="../selectdauforpacketservlet">
                            <div class="form-group">
                                <label for="dau">Birim Seçiniz</label>
                                <select id="dau" name="unit" class="form-control">
                                    <c:forEach var="item" items="${dauList}">
                                        <c:if test="${item.unitName ne 'Tüm Birimler'}">
                                            <option value="${item.unitName}">
                                                <c:out value="${item.unitName}"/>
                                            </option>
                                        </c:if>
                                    </c:forEach>
                                </select>
                            </div>
                            <button type="submit" class="btn btn-default">Seç</button>
                        </form>
                    </div>
                </div>
                <div class="col-md-1"></div>
                <div class="col-md-6">
                    <c:choose>
                        <c:when test="${vakifsecildi eq 1}">
                            <h4>${dau.unitName} birimi için ilan paketi oluşturun</h4>
                            <form method="post" action="../createannouncementpackageservlet" >
                                <table class="table" id="formTable">
                                  <tbody>
                                    <tr>
                                      <td>Paketin adı</td>
                                      <td><input type="text" name="packet_name" class="form-control"/>
                                    </tr>
                                    <tr>
                                      <td>Pakette yer alacak ilan sayısı</td>
                                      <td><input type="text" name="announcement_number" class="form-control"/></td>
                                    </tr>
                                    <tr>
                                        <td>Paketin son kullanım tarihi</td>
                                        <td><input type="text" id="last_date_used" class="form-control" name="last_date_used"/></td>
                                    </tr>
                                    <tr>
                                        <td>İlanların aktif kalma süresi (Gün)</td>
                                        <td><input type="text" name="activate_date" class="form-control"/></td>
                                    </tr>
                                    <tr>
                                        <td>Paket fiyatı (TL)</td>
                                        <td><input type="text" name="price" class="form-control"/></td>
                                    </tr>
                                    <tr>
                                        <td>Vakfa/derneğe ait banka hesabı</td>
                                        <td>
                                            <select name="account" class="form-control">
                                                <c:forEach var="item" items="${accountList}">
                                                <option value="${item.iban}">
                                                    <c:out value="${item.iban}"/>
                                                </option>
                                            </c:forEach>
                                            </select>
                                        </td>
                                    </tr>
                                    <tr>
                                        <td>Para birimi</td>
                                        <td><select disabled name="currency" class="form-control">
                                            <c:forEach var="item" items="${curr}">
                                                <option value="${item.id}">
                                                    <c:out value="${item.title}"/>
                                                </option>
                                            </c:forEach>
                                        </select></td>
                                    </tr>
                                    <tr>
                                        <td>Açıklama giriniz</td>
                                        <td><textarea rows="5" cols="35" name="condition" class="form-control"></textarea></td>
                                    </tr>
                                    <tr><td colspan="2"><button type="submit" class="btn btn-default">Oluştur</button></td></tr>

                                  </tbody>
                                </table>
                            </form>
                        </c:when>
                        <c:when test="${vakifsecildi eq 2 }">
                            <div class="alert alert-danger">
                                Bir hata oluştu. Lütfen daha sonra tekrar deneyin.
                            </div>
                        </c:when>
                    </c:choose>
                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/footer.html"/>
    </body>
</html>
