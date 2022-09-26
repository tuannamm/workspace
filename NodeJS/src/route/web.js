import express from "express";
import homecontroller from "../controller/homeController.js";
let router = express.Router();

const initWebRoute = (app) => {
  router.get("/", func.getHomepage);

  router.get("/about", (req, res) => {
    res.send(`I'm Nam!`);
  });

  return app.use("/", router);
};

export default initWebRoute;
