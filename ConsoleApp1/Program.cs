using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using HtmlAgilityPack;
using System.Net;
using System.Net.Http;
using System.IO;

namespace Parser
{
    class Program
    {
        static void Main(string[] args)
        {

            var web = new HtmlWeb();
            HtmlDocument doc = web.Load("http://html-agility-pack.net/");
            string downloads = doc.DocumentNode
                .SelectSingleNode("//*[@id='downloadCount']/div[2]")
                .InnerText.Trim();////div[contains(@class, 'style-4')]

            Console.WriteLine(downloads);
            Console.ReadLine();

        }
    }
}