import express from "express";
import helmet from "helmet";
import cors from "cors";
// eslint-disable-next-line import/no-extraneous-dependencies
import multer from "multer";

import authMiddleware from "./middlewares";
import Controller from "./controller";

require("dotenv").config();

const app = express();

app.use(helmet());
app.use(helmet.crossOriginResourcePolicy({ policy: "cross-origin" }));

app.use(cors());
app.use(express.json());
// serve as /product_images
app.use("/product_images", express.static("product_images"));

// app.get("/", authMiddleware, (req, res) => {
//   res.json({ x: Database.getOrders(1) });
// });

const storage = multer.diskStorage({
  destination: function (req, file, cb) {
    cb(null, "./product_images");
  },
  filename: function (req, file, cb) {
    const uniqueSuffix = Date.now() + "-" + Math.round(Math.random() * 1e9);
    cb(
      null,
      file.fieldname +
        "-" +
        uniqueSuffix +
        "." +
        // eslint-disable-next-line
        file.originalname.split(".")[file.originalname.split(".").length - 1]
    );
  },
});
const upload = multer({ storage: storage });

// app.get("/test", async (req, res) => {
//   const cevap = await Database.getSingleUserInformation("2");

//   res.json({
//     message: cevap,
//   });
// });

app.post("/login", Controller.login); // login
app.get("/checkSession", authMiddleware, (req, res) => {
  res.json({ status: true });
}); // if request can pass authMiddleware, session is valid
app.post("/changePassword", authMiddleware, Controller.changePassword); // change password
app.post("/register", Controller.register);

app.get("/profile", authMiddleware, Controller.getProfile); // get profile

app.post("/profile", authMiddleware, Controller.updateProfile); // update profile //ok mis gibi

app.get("/products", Controller.getProducts); // get all products // name,price,image
app.get("/products/:id", authMiddleware, Controller.getSingleProduct); // get single product // yourmları unutmayın

app.get("/myproducts", authMiddleware, Controller.getMyProducts); // get my products

app.post(
  "/myproducts",
  authMiddleware,
  upload.single("file"),
  // eslint-disable-next-line @typescript-eslint/comma-dangle
  Controller.addProduct
); // add product // image için form-data

app.put(
  "/myproducts",
  authMiddleware,
  upload.single("file"),
  // eslint-disable-next-line @typescript-eslint/comma-dangle
  Controller.editProduct
); // edit product // image için form-data

app.delete("/myproducts/:id", authMiddleware, Controller.deleteSingleProduct); // delete single product

app.get("/cart", authMiddleware, Controller.getCart); // get cart
app.post("/cart", authMiddleware, Controller.addToCart); // add to cart (product id)
app.put("/cart", authMiddleware, Controller.changeQuantityInCart); // add to cart (product_id,     (+1,-1))
app.delete("/cart", authMiddleware, Controller.deleteCart); // add to cart (product id)

app.post("/order", authMiddleware, Controller.addOrder); // sipariş yap
app.get("/order", authMiddleware, Controller.getPrevOrders); // get sipariş geçmişi

app.get("/purchases", authMiddleware, Controller.getPreviousPurchases); // get previous purchases
app.post("/comment", authMiddleware, Controller.addCommentToProduct); // add comment (product_id, comment, star(1 -5))

app.get("/search/:key", authMiddleware, Controller.searchProducts); // search (query: string)
app.get("/filter/:price", authMiddleware, Controller.filterStock); // search (query: string)

export default app;
