<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<style>
    .modal-header, h4, .close {
        background-color: #5cb85c;
        color:white !important;
        text-align: center;
        font-size: 30px;
    }
    .modal-footer {
        background-color: #f9f9f9;
    }
</style>


<!-- Modal -->
  <div class="modal fade" id="loginModal" role="dialog">
    <div class="modal-dialog">
    
      <!-- Modal content-->
      <div class="modal-content">
        <div class="modal-header" style="padding:35px 50px";>
          <button type="button" class="close" data-dismiss="modal">&times;</button>
          <h4><span class="glyphicon glyphicon-lock"></span> Hesabınıza Giriş Yapın</h4>
        </div>
        <div class="modal-body" style="padding:40px 50px;">
          <form  action="logincontrolservlet" method="post" role="form">
            <div class="form-group">
              <label for="username"><span class="glyphicon glyphicon-user"></span> Kullanıcı Adı</label>
              <input type="text" name="username" class="form-control" id="username" value="${username}" pattern=".{1,20}"
        				required title="Lütfen kullanıcı adınızı giriniz">
            </div>
            <div class="form-group">
              <label for="password"><span class="glyphicon glyphicon-eye-open"></span> Parola</label>
              <input type="password" name="password" class="form-control" id="password" value="${password}">
            </div>
            <div class="checkbox">
              <label><input type="checkbox" name="rememberMe" value="1">Beni Hatırla</label>
            </div>
              <button type="submit" class="btn btn-success btn-block"><span class="glyphicon glyphicon-off"></span> Giriş Yap</button>
          </form>
        </div>
        <div class="modal-footer">
          <button type="submit" class="btn btn-danger btn-default pull-left" data-dismiss="modal">
          	<span class="glyphicon glyphicon-remove"></span> Kapat
          </button>
          <p>Üye değil misininiz?</p>
          <p><a href="studentsaveinitializeservlet">Öğrenci kayıt</a></p>
          <p><a href="companysaveinitializeservlet">Şirket Kayıt</a></p>
          <p><a href="newpasswordrequest" class="btn btn-info">Parolamı Unuttum</a></p>
        </div>
      </div>
      
    </div>
  </div> 

<div class="container-fluid">
    <div class="row">
        <div class="col-md-2 text-center"><img src="logo/yildiz.png"></div>
        <div class="col-md-7 text-center"><h1>YTÜ İlan Yayınlama Servisi</h1></div>
        <div class="col-md-3 text-center">
            <ul class="nav navbar-nav ">
                <li><a data-toggle="modal" href="#loginModal"><span class="glyphicon glyphicon-log-in"></span> Giriş Yap</a></li>
                <li class="dropdown">
                    <a class="dropdown-toggle" data-toggle="dropdown" href="#"><span class="glyphicon glyphicon-user"></span> Kayıt Ol
                    <span class="caret"></span></a>
                    <ul class="dropdown-menu">
                        <li><a href="studentsaveinitializeservlet">Öğrenci</a></li>
                        <li><a href="companysaveinitializeservlet">Şirket</a></li>
                    </ul>
                </li>
            </ul>
        </div>
    </div>
    <div class="row">
        <div class="col-md-4 text-center">
        	<a href="index.jsp" class="btn btn-info btn-lg">
        		<span class="glyphicon glyphicon-home"></span> Anasayfa
        	</a>
        </div>
        <div class="col-md-4 text-center">
        	<a href="nasil-calisir.jsp" class="btn btn-info btn-lg">
        		<span class="glyphicon glyphicon-question-sign"></span> Nasıl Çalışır
        	</a>
        </div>
        <div class="col-md-4 text-center">
        	<a href="directiletisimservlet" class="btn btn-info btn-lg">
        		<span class="glyphicon glyphicon-envelope"></span> İletişim
        	</a>
        </div>
    </div>
</div>

</html>
