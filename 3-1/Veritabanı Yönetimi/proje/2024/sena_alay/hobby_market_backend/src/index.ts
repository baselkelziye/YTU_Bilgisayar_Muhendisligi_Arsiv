import app from "./app";

declare global {
  namespace Express {
    interface Request {
      userId: number;
    }
  }
}

const port = process.env.PORT || 9000;
app.listen(port, () => {
  /* eslint-disable no-console */
  console.log(`Listening: http://localhost:${port}`);
  /* eslint-enable no-console */
});
