/* eslint-disable */

import Database from "./database";

import { Request, Response } from "express";
class Controller {
  async login(req: Request, res: Response) {
    const { username, password } = req.body;

    // burada veritabanına gidip kullanıcıyı kontrol edeceğiz
    const user = await Database.getUserPassword(username);

    if (!user) {
      res.status(404).json({
        message: "Kullanıcı bulunamadı",
      });
      return;
    }

    if (user.password !== password) {
      res.status(404).json({
        message: "Şifre yanlış",
      });
    } else {
      const access_token = Math.random().toString(36).slice(2) + Date.now();

      const res2 = await Database.insertAccessToken(access_token, user.user_id);

      res.status(200).json({
        status: true,
        message: "Giriş başarılı",
        access_token: access_token,
      });
    }
  }

  async getProfile(req: Request, res: Response) {
    const user = await Database.getSingleUserInformation(req.userId);

    res.json({
      status: true,
      data: user,
    });
  }

  async updateProfile(req: Request, res: Response) {
    const name = req.body.name;
    const surname = req.body.surname;
    const email = req.body.email;
    const address = req.body.address;
    const phone = req.body.phone;

    await Database.updateProfile(
      name,
      surname,
      email,
      address,
      phone,
      req.userId
    );

    res.json({
      status: true,
      data: { name, surname, email, address, phone },
    });
  }

  async changePassword(req: Request, res: Response) {
    const newPassword = req.body.password;
    const passwordRpt = req.body.passwordRpt;

    if (newPassword !== passwordRpt) {
      res.status(404).json({
        message: "Şifreler uyuşmuyor",
      });
      return;
    }

    const status = await Database.changeUserPassword(newPassword, req.userId);

    if (!status) {
      res.status(404).json({
        message: "Şifre değiştirilemedi",
      });
      return;
    }

    res.json({
      status: true,
      message: "Şifre değiştirildi",
    });
  }

  async getMyProducts(req: Request, res: Response) {
    const products = await Database.getMyProducts(req.userId);
    res.json({
      status: true,
      data: products,
    });
  }

  async getSingleProduct(req: Request, res: Response) {
    const id = req.params.id;
    const product = await Database.getSingleProduct(Number(id));
    res.json({
      status: true,
      data: product,
    });
  }

  async addProduct(req: Request, res: Response) {
    const product_name = req.body.product_name;
    const description = req.body.description;
    const price = req.body.price;
    const image = req.file?.path || "";
    const seller_id = req.userId;
    const stock = req.body.stock;
    const sales_amounts = 0;

    await Database.addProduct(
      product_name,
      description,
      price,
      image,
      seller_id,
      stock,
      sales_amounts
    );

    res.json({
      status: true,
      data: { product_name, description, price, image, seller_id, stock },
    });
  }

  async editProduct(req: Request, res: Response) {
    const product_id = req.body.product_id;
    const product_name = req.body.product_name;
    const description = req.body.description;
    const price = req.body.price;
    const image = req.file?.path || "";
    const seller_id = req.userId;
    const stock = req.body.stock;

    await Database.editProduct(
      product_id,
      product_name,
      description,
      price,
      image,
      seller_id,
      stock
    );

    res.json({
      status: true,
      data: { product_name, description, price, image, seller_id, stock },
    });
  }

  async getProducts(req: Request, res: Response) {
    const products = await Database.getProducts();
    res.json({
      status: true,
      data: products,
    });
  }

  async searchProducts(req: Request, res: Response) {
    const key = (req.params.key as string) ?? "";

    let products = await Database.searchProduct(key);

    products = products.map((product) => product.product_id);

    res.json({
      status: true,
      data: products,
    });
  }

  async filterStock(req: Request, res: Response) {
    const price = (req.params.price as string) ?? "999";

    let products = await Database.filterStock(Number(price));

    products = products.map((product) => product.product_id);

    res.json({
      status: true,
      data: products,
    });
  }

  async deleteSingleProduct(req: Request, res: Response) {
    const id = req.params.id;
    const product = await Database.deleteSingleProduct(Number(id));
    res.json({
      status: true,
      data: product,
    });
  }

  async getCart(req: Request, res: Response) {
    const cart = await Database.getCart(req.userId);
    res.json({
      status: true,
      data: cart,
    });
  }

  async addToCart(req: Request, res: Response) {
    const productId = req.body.productId;
    const cart = await Database.addToCart(productId, req.userId);
    res.json({
      status: true,
      data: cart,
    });
  }

  async changeQuantityInCart(req: Request, res: Response) {
    const productId = req.body.productId;
    const isRemoving = req.body.isRemoving;
    const cart = await Database.changeQuantityInCart(
      productId,
      req.userId,
      isRemoving
    );
    if (typeof cart === "string") {
      res.status(200).json({
        status: false,
        message: cart,
      });
    } else {
      res.json({
        status: true,
        data: cart,
      });
    }
  }

  async deleteCart(req: Request, res: Response) {
    const cart_id = req.body.cart_id;
    const cart = await Database.deleteCart(req.userId, cart_id);
    res.json({
      status: true,
      data: cart,
    });
  }

  async addOrder(req: Request, res: Response) {
    const orders = await Database.addOrder(req.userId);
    res.json({
      status: true,
      data: orders,
    });
  }

  async getPrevOrders(req: Request, res: Response) {
    const orders = await Database.getPreviousPurchases(req.userId);

    res.json({
      status: true,
      data: orders,
    });
  }

  async getPreviousPurchases(req: Request, res: Response) {
    const purchases = await Database.getPreviousPurchases(req.userId);
    res.json({
      status: true,
      data: purchases,
    });
  }

  async addCommentToProduct(req: Request, res: Response) {
    const productId = req.body.productId;
    const comment = req.body.comment;
    const star = req.body.star;

    await Database.addCommentToProduct(productId, req.userId, star, comment);

    res.json({
      status: true,
      data: { productId, comment, star },
    });
  }

  async register(req: Request, res: Response) {
    const username = req.body.username;
    const password = req.body.password;
    const passwordRpt = req.body.passwordRpt;
    const name = req.body.name;
    const surname = req.body.surname;
    const email = req.body.email;
    const address = req.body.address;
    const phone = req.body.phone;

    if (password !== passwordRpt) {
      res.status(404).json({
        message: "Şifreler uyuşmuyor",
      });
      return;
    }

    const user = await Database.registerUser(
      username,
      password,
      name,
      surname,
      email,
      address,
      phone
    );

    res.json({
      status: true,
      data: user,
    });
  }
}

export default new Controller();
