/* eslint-disable */

import { Client } from "pg";
import * as fs from "fs";

const client = new Client({
  host: "veri-projesi-pgsql-db1-do-user-14764159-0.c.db.ondigitalocean.com",
  password: "AVNS_lJoFQMa-c2voJS-hLDP",
  database: "hobi_pazarı_son",
  user: "doadmin",
  port: 25060,
  ssl: {
    ca: fs.readFileSync("ca-certificate.crt").toString(),
  },
});

class Database {
  constructor() {
    client.connect();
  }

  async getSingleUserInformation(userId: number) {
    // burası tekli kullanıcı alamya yarar
    const res = await client.query(
      "SELECT u.username, ui.* from user_informations ui,users u where ui.user_id = $1 AND u.user_id = $1",
      [userId]
    );

    return res.rows[0];
  }

  async getUserPassword(username: string) {
    // burası tekli kullanıcı alamya yarar
    const res = await client.query("SELECT * from users where username = $1", [
      username,
    ]);

    return res.rows[0];
  }

  async changeUserPassword(password: string, user_id: number) {
    // burası tekli kullanıcı alamya yarar
    const res = await client.query(
      "UPDATE users set password = $1 where user_id = $2",
      [password, user_id]
    );

    return res;
  }

  async registerUser(
    username: string,
    password: string,
    name: string,
    surname: string,
    email: string,
    address: string,
    phone: string
  ) {
    const res = await client.query(
      "INSERT INTO users (user_id, username, password) VALUES (NEXTVAL('SEQ_USERS'),$1,$2)",
      [username, password]
    );

    const res2 = await client.query(
      "INSERT INTO user_informations (user_id, first_name, last_name, email, address, phone_number) VALUES (CURRVAL('SEQ_USERS'),$1,$2,$3,$4,$5)",
      [name, surname, email, address, phone]
    );

    return res;
  }

  async insertAccessToken(access_token: string, userId: string) {
    const res = await client.query(
      "INSERT into access_tokens (access_token, user_id) values ($1, $2)",
      [access_token, userId]
    );

    return res;
  }

  async validateAccessToken(access_token: string): Promise<number> {
    const res = await client.query(
      "SELECT * from access_tokens where access_token = $1",
      [access_token]
    );

    if (res.rowCount == 0) return -1;

    return res.rows[0].user_id as number;
  }

  async updateProfile(
    name: string,
    surname: string,
    email: string,
    address: string,
    phone: string,
    userId: number
  ) {
    const res = await client.query(
      "UPDATE user_informations SET first_name = $1, last_name = $2, email = $3, address = $4, phone_number = $5 WHERE user_id = $6",
      [name, surname, email, address, phone, userId]
    );

    return res;
  }

  // başlatmak için:npm run dev
  async getProducts() {
    // stars, image, price, pro_id, name

    const res = await client.query("select * from get_all_products_view");
    return res.rows;
  }

  async getMyProducts(userId: number) {
    // stars, image, price, pro_id, name
    const res = await client.query(
      "select * from products where seller_id = $1",
      [userId]
    );
    return res.rows;
  }

  async getSingleProduct(productId: number) {
    // stars(avg), comments, image, price, id, name, description, stock, sales_amount, (comments=name_surname_comment_star)
    const res = await client.query("select * from getsingleproduct($1)", [
      productId,
    ]);
    return res.rows[0];
  }

  async deleteSingleProduct(productId: number) {
    const res = await client.query(
      "delete from products where product_id = $1",
      [productId]
    );
    if (res.rowCount == 0) return "BULUNAMADI";
    else return "product_id = " + productId + " silindi.";
  }

  async getCart(userId: number) {
    //cart_id, iamge, pro_name, price, quantity
    const res = await client.query(
      `
        select  c.cart_id as id , quantity as qty , p.product_name as name, p.price, p.image
        from cart c
        left join products p ON p.product_id = c.product_id
        where user_id = $1
        `,
      [userId]
    );
    return res.rows;
  }

  async addToCart(productId: number, userId: number) {
    const res0 = await client.query(
      "SELECT quantity FROM cart WHERE product_id = $1 and user_id = $2",
      [productId, userId]
    );
    if (res0.rowCount == 0) {
      const res = await client.query(
        "INSERT INTO cart (cart_id,user_id,product_id,quantity) VALUES  (NEXTVAL('SEQ_CART'),$1,$2,1)",
        [userId, productId]
      );
      return (
        "Product_id = " + productId + "   user_id = " + userId + "   eklendi."
      );
    } else {
      const res = await client.query(
        "UPDATE cart SET quantity = quantity + 1 WHERE user_id = $1 and product_id = $2",
        [userId, productId]
      );
      return (
        "Product_id = " +
        productId +
        "   user_id = " +
        userId +
        "   eklendi.(+1)"
      );
    }
  }

  async changeQuantityInCart(
    productId: number,
    userId: number,
    isRemoving: boolean
  ) {
    const res = await client.query(
      "select quantity from cart where cart_id = $1 and user_id = $2",
      [productId, userId]
    );

    const quan = res.rows[0].quantity;
    console.log("q", quan);
    if (!isRemoving) {
      //ekleme
      try {
        const res = await client.query(
          "UPDATE cart SET quantity = quantity + 1 WHERE user_id = $1 and cart_id = $2",
          [userId, productId]
        );
      } catch (e: any) {
        return e.message;
      }

      console.log("a", res);
    } else {
      //eksiltme
      if (quan > 0) {
        const res = await client.query(
          "UPDATE cart SET quantity = quantity - 1 WHERE user_id = $1 and cart_id = $2",
          [userId, productId]
        );
        console.log("b", res);
      } else {
        console.log("c", res);
        return "yok";
      }
    }

    return res.rows;
  }

  async deleteCart(userId: number, cart_id: number) {
    const res = await client.query(
      "delete from cart where user_id = $1 AND cart_id = $2",
      [userId, cart_id]
    );
    if (res.rowCount == 0) {
      return "BULUNAMADI";
    } else {
      return "user_id = " + userId + " olan bütün cartlar silindi.";
    }
  }

  async addOrder(userId: number) {
    // cartı purchase tablosuna getirmek ve cartı boşaltmak

    const cart = await client.query(
      "select product_id, quantity from cart where user_id=$1",
      [userId]
    );
    const adres = await client.query(
      "select address from user_informations where user_id=$1",
      [userId]
    );

    if (cart.rowCount == null) return "cart null";

    for (let i = 0; i < cart.rowCount; i++) {
      const res = await client.query(
        "INSERT INTO purchases (purchase_id,user_id,product_id,quantity,address,purchase_date) VALUES  (NEXTVAL('SEQ_PURCHASE'), $1, $2, $3, $4, CURRENT_TIMESTAMP)",
        [
          userId,
          cart.rows[i].product_id,
          cart.rows[i].quantity,
          adres.rows[0].address,
        ]
      );
    }
    const res0 = await client.query("delete from cart where user_id = $1", [
      userId,
    ]);
  }

  async getPreviousPurchases(userId: number) {
    const res = await client.query(
      `select * from purchases 
      join products on products.product_id = purchases.product_id 
      where user_id=$1`,
      [userId]
    );
    return res.rows;
  }

  async addCommentToProduct(
    productId: number,
    userId: number,
    star: number,
    comment: string
  ) {
    const res = await client.query(
      "INSERT INTO comments (comment_id,product_id,user_id,stars,comment) VALUES (NEXTVAL('SEQ_COMMENTS'),$1,$2,$3,$4)",
      [productId, userId, star, comment]
    );
    if (res.rowCount != 0) {
      return (
        "user_İd = " +
        userId +
        ", product_id = " +
        productId +
        ", comment eklendi."
      );
    } else {
      return "eklenemedi";
    }
  }

  async addProduct(
    productName: string,
    description: string,
    price: number,
    image: string,
    userId: number,
    stock: number,
    sales_amounts: number
  ) {
    const res = await client.query(
      "INSERT INTO products (product_id, seller_id, image, product_name, description, stock, price, sales_amounts) VALUES (NEXTVAL('SEQ_PROD'),$1,$2,$3,$4,$5,$6,$7)",
      [userId, image, productName, description, stock, price, sales_amounts]
    );
    return res.rows;
  }

  async editProduct(
    product_id: number,
    productName: string,
    description: string,
    price: number,
    image: string,
    userId: number,
    stock: number
  ) {
    const res = await client.query(
      "UPDATE products SET image = $2, product_name = $3, description = $4, stock = $5, price = $6 WHERE product_id = $1 AND seller_id = $7",
      [product_id, image, productName, description, stock, price, userId]
    );
    return res.rows;
  }

  async filterStock(price: number) {
    const res = await client.query(
      "Select product_id from products where stock >= 0 intersect select product_id from products where price < $1",
      [price]
    );
    return res.rows;
  }

  async searchProduct(key: string) {
    const res = await client.query(
      "select product_id from products where product_name LIKE $1",
      ["%" + key + "%"]
    );
    return res.rows;
  }
}
export default new Database();
