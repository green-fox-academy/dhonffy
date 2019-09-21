using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using BasicWebshop.Models;
using Microsoft.AspNetCore.Mvc;

namespace BasicWebshop.Controllers
{
    public class HomeController : Controller
    {
        [HttpGet("/Show")]
        public IActionResult Show()
        {
            List<ShopItem> list = new List<ShopItem>();
            var shopItem = new ShopItem() { Name = "Running shoes", Description = "asdf", Price = 1000.0, QuantityOfStock = 5 };
            list.Add(shopItem);
            shopItem = new ShopItem() { Name = "Printer", Description = "assssdf", Price = 3000.0, QuantityOfStock = 2 };
            list.Add(shopItem);
            shopItem = new ShopItem() { Name = "Coca cola", Description = "asdéáéáf", Price = 25.0, QuantityOfStock = 0 };
            list.Add(shopItem);
            return View("Show", list);
        }

        /*[HttpGet("/Show")]
        public IActionResult Search()
        {

            return View();
        }*/

        [HttpPost("/Show")]
        public IActionResult Search()
        {
            var searchedItem = new SearchedItem() { };
            return View("Show", searchedItem);
        }
    }
}