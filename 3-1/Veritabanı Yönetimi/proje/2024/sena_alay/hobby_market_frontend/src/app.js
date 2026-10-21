const express = require("express");
const API = require("./API");
const cookieParser = require("cookie-parser");
const cors = require("cors");

app = express();
app.use(express.static("static"));
app.set("view engine", "ejs");
app.use(cookieParser());
app.use(cors());

app.get("/login", async (req, res) => {
  res.render("login");
});

app.use("/*", async (req, res, next) => {
  if (await API.CheckSession(req.cookies.access_token ?? "")) {
    req.ACTK = req.cookies.access_token;
    next();
  } else {
    res.redirect("/login");
  }
});

app.get("/", async (req, res) => {
  const products = await API.getAllProducts();
  res.render("home", { products });
});

app.get("/product/:id", async (req, res) => {
  const product = await API.getSingleProducts(req.params.id, req.ACTK);
  res.render("product", { product });
});

app.get("/profile", async (req, res) => {
  const profile = await API.GetMyProfile(req.ACTK);
  res.render("profile", { profile });
});

app.get("/cart", async (req, res) => {
  const cart = await API.GetMyCart(req.ACTK);
  res.render("cart", { cart });
});

app.get("/my_products", async (req, res) => {
  const products = await API.GetMyProducts(req.ACTK);
  res.render("myproducts", { products });
});

app.get("/order_history", async (req, res) => {
  const products = await API.GetPrevOrders(req.ACTK);
  res.render("order_history", { products });
});

app.get("/add_product", async (req, res) => {
  res.render("add_product");
});

app.get("/error_page", async (req, res) => {
  res.render("error_page");
});

app.get("/edit_product/:id", async (req, res) => {
  const product = await API.getSingleProducts(req.params.id, req.ACTK);
  console.log(product);
  res.render("edit_product", { product });
});

app.listen(8080, function () {
  console.log("Server is running on port 8080 ");
});
