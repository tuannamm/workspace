import express from "express";

const configViewEngine = (app) => {
  app.use(express.static("./src/public"));
  app.set("view engine", "ejs"); // cấu hình view engine là ejs
  app.set("views", "./src/views"); // cấu hình nơi tìm các file ejs => phải đặt ejs trong folder views
};

export default configViewEngine;
