import express from "express";
import configViewEngine from "./configs/viewEngine.js";
import initWebRoute from "./route/web.js";
// require("dotenv").config();

const app = express();
const port = 3000;

// setup view engine
configViewEngine(app);

// init web route
initWebRoute(app);

app.listen(port, () => {
  console.log(`Example app listening at http://localhost:${port}`);
});
