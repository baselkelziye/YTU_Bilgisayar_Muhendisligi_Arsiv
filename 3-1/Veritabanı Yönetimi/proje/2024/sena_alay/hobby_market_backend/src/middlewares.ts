import { NextFunction, Request, Response } from "express";
import database from "./database";

export default async function authMiddleware(
  // eslint-disable-next-line
  req: Request,
  // eslint-disable-next-line
  res: Response,
  // eslint-disable-next-line
  next: NextFunction
) {
  // read the query
  // eslint-disable-next-line
  const access_token = req.headers["authorization"];

  const userId = await database.validateAccessToken(access_token as string);

  if (userId == -1) {
    res.status(401).json({
      status: false,
      error: "Invalid access token",
    });
  } else {
    req.userId = userId;
    next();
  }
}
