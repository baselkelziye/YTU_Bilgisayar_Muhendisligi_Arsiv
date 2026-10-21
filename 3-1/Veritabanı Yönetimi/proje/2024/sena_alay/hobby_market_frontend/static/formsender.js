let sleep = (ms) => new Promise((resolve) => setTimeout(resolve, ms));
const SERVER_URL = "http://165.227.132.99/api";
const ACTK = document.cookie.split("=")[1];
const FormSender = {
  AddToCart: async (id) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", ACTK);
    myHeaders.append("Content-Type", "application/json");

    var raw = JSON.stringify({
      productId: id,
    });

    var requestOptions = {
      method: "POST",
      headers: myHeaders,
      body: raw,
      redirect: "follow",
    };

    const rawRes = await fetch(SERVER_URL + "/cart", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return true;
    }
  },
  Login: async (username, password) => {
    var myHeaders = new Headers();
    myHeaders.append("Content-Type", "application/json");

    var raw = JSON.stringify({
      username,
      password,
    });

    var requestOptions = {
      method: "POST",
      headers: myHeaders,
      body: raw,
      redirect: "follow",
    };

    const rawRes = await fetch(SERVER_URL + "/login", requestOptions);

    const res = await rawRes.json();
    if (!res.status) {
      return false;
    } else {
      return res.access_token;
    }
  },
  Register: async (
    username,
    password,
    passwordRpt,
    name,
    surname,
    email,
    phone,
    address
  ) => {
    var myHeaders = new Headers();
    myHeaders.append("Content-Type", "application/json");

    var raw = JSON.stringify({
      username,
      password,
      passwordRpt,
      name,
      surname,
      email,
      phone,
      address,
    });

    var requestOptions = {
      method: "POST",
      headers: myHeaders,
      body: raw,
      redirect: "follow",
    };

    const rawRes = await fetch(SERVER_URL + "/register", requestOptions);

    const res = await rawRes.json();
    if (!res.status) {
      return false;
    } else {
      return true;
    }
  },

  EditProfile: async (name, surname, email, phone, address) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", ACTK);
    myHeaders.append("Content-Type", "application/json");

    var raw = JSON.stringify({
      name,
      surname,
      email,
      phone,
      address,
    });

    var requestOptions = {
      method: "POST",
      headers: myHeaders,
      body: raw,
      redirect: "follow",
    };

    const rawRes = await fetch(SERVER_URL + "/profile", requestOptions);

    const res = await rawRes.json();
    if (!res.status) {
      return false;
    } else {
      return true;
    }
  },

  ChangePassword: async (password, passwordRpt) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", ACTK);
    myHeaders.append("Content-Type", "application/json");

    var raw = JSON.stringify({
      password,
      passwordRpt,
    });

    var requestOptions = {
      method: "POST",
      headers: myHeaders,
      body: raw,
      redirect: "follow",
    };

    const rawRes = await fetch(SERVER_URL + "/changePassword", requestOptions);

    const res = await rawRes.json();
    if (!res.status) {
      return false;
    } else {
      return true;
    }
  },

  ChangeQty: async (id, qty) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", ACTK);
    myHeaders.append("Content-Type", "application/json");

    var raw = JSON.stringify({
      productId: id,
      isRemoving: qty == 1 ? false : true,
    });

    var requestOptions = {
      method: "PUT",
      headers: myHeaders,
      body: raw,
      redirect: "follow",
    };

    const rawRes = await fetch(SERVER_URL + "/cart", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return res.message;
    } else {
      return true;
    }
  },

  DeleteFromCart: async (PID) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", ACTK);
    myHeaders.append("Content-Type", "application/json");

    var raw = JSON.stringify({
      cart_id: PID,
    });

    var requestOptions = {
      method: "DELETE",
      headers: myHeaders,
      body: raw,
      redirect: "follow",
    };

    const rawRes = await fetch(SERVER_URL + "/cart", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return true;
    }
  },

  AddOrder: async () => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", ACTK);

    var requestOptions = {
      method: "POST",
      headers: myHeaders,
    };

    const rawRes = await fetch(SERVER_URL + "/order", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return true;
    }
  },

  DeleteMyProduct: async (id) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", ACTK);
    myHeaders.append("Content-Type", "application/json");

    var requestOptions = {
      method: "DELETE",
      headers: myHeaders,
      redirect: "follow",
    };

    const rawRes = await fetch(
      SERVER_URL + "/myproducts/" + id,
      requestOptions
    );
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return true;
    }
  },

  SendComment: async (id, comment, stars) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", ACTK);
    myHeaders.append("Content-Type", "application/json");

    var raw = JSON.stringify({
      productId: id,
      comment,
      star: stars,
    });

    var requestOptions = {
      method: "POST",
      headers: myHeaders,
      body: raw,
    };

    const rawRes = await fetch(SERVER_URL + "/comment", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return true;
    }
  },
};
