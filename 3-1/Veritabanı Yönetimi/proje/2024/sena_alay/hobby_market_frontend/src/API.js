let sleep = (ms) => new Promise((resolve) => setTimeout(resolve, ms));

const SERVER_URL = "http://165.227.132.99/api";

const API = {
  CheckSession: async (access_token) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", access_token);
    var requestOptions = {
      method: "GET",
      headers: myHeaders,
    };
    const rawRes = await fetch(SERVER_URL + "/checkSession", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return true;
    }
  },

  getAllProducts: async (access_token) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", access_token);

    var requestOptions = {
      method: "GET",
      headers: myHeaders,
      redirect: "follow",
    };

    const rawRes = await fetch(SERVER_URL + "/products", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return res.data;
    }
  },

  getSingleProducts: async (id, AC_TK) => {
    await sleep(300);
    var myHeaders = new Headers();
    myHeaders.append("authorization", AC_TK);

    var requestOptions = {
      method: "GET",
      headers: myHeaders,
      redirect: "follow",
    };

    const rawRes = await fetch(SERVER_URL + "/products/" + id, requestOptions);
    const res = await rawRes.json();
    if (!res.status) {
      return false;
    }

    let comments = parseTuppleToJSON(res.data.comments);

    return {
      id: res.data.product_id,
      image: res.data.image,
      name: res.data.product_name,
      description: res.data.description ?? "",
      price: res.data.price,
      stock: res.data.stock,
      sold: res.data.sales_amount,
      stars: res.data.stars,
      comments: comments,
    };
  },

  AddToCart: async (id) => {
    await sleep(300);

    return true;
  },

  GetMyProfile: async (AC_TK) => {
    await sleep(300);

    var myHeaders = new Headers();
    myHeaders.append("authorization", AC_TK);
    var requestOptions = {
      method: "GET",
      headers: myHeaders,
    };
    const rawRes = await fetch(SERVER_URL + "/profile", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return res.data;
    }
  },

  GetMyCart: async (AC_TK) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", AC_TK);

    var requestOptions = {
      method: "GET",
      headers: myHeaders,
    };

    const rawRes = await fetch(SERVER_URL + "/cart", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return res.data;
    }
  },

  GetMyProducts: async (AC_TK) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", AC_TK);

    var requestOptions = {
      method: "GET",
      headers: myHeaders,
    };

    const rawRes = await fetch(SERVER_URL + "/myproducts", requestOptions);
    const res = await rawRes.json();

    if (!res.status) {
      return false;
    } else {
      return res.data;
    }
  },

  GetPrevOrders: async (AC_TK) => {
    var myHeaders = new Headers();
    myHeaders.append("authorization", AC_TK);

    var requestOptions = {
      method: "GET",
      headers: myHeaders,
    };

    const rawRes = await fetch(SERVER_URL + "/order", requestOptions);
    const res = await rawRes.json();
    console.log(res);
    if (!res.status) {
      return false;
    } else {
      return res.data;
    }
  },
};

module.exports = API;

parseTuppleToJSON = (inputString) => {
  try {
    var comments = inputString.slice(1, -1).split('","');
    comments = comments.map((tuple) => {
      //   tuple = tuple.replaceAll('"', "");
      //   tuple = tuple.replaceAll("\\", "");

      tuple = tuple.replaceAll("'", "");
      tuple = tuple.replaceAll("(", "");
      tuple = tuple.replaceAll(")", "");

      tuple = tuple.split(",\\");
      tuple[1] = tuple[1].split('\\",');
      tuple = [tuple[0], tuple[1][0], tuple[1][1]];
      tuple[0] = tuple[0].replaceAll('"', "");
      tuple[0] = tuple[0].replaceAll("\\", "");
      tuple[0] = tuple[0].replaceAll(",", " ");
      tuple[1] = tuple[1].replaceAll('"', "");
      tuple[1] = tuple[1].replaceAll("\\", "");
      tuple[2] = tuple[2].replaceAll('"', "");
      tuple[2] = tuple[2].replaceAll("\\", "");

      return {
        fullname: tuple[0],
        comment: tuple[1],
        stars: tuple[2],
      };
    });

    return comments;
  } catch (e) {
    return [];
  }
};
