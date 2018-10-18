using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace array
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] number = new int[10];
            number[0] = 0;
            number[1] = 1;
            number[2] = 2;
            number[3] = 3;
            number[4] = 4;
            ////khuc sau rong la null =0
            string[] names = new string[] { "\ntu,nhi,lam,hung,phuong" };
            foreach (string name in names)
            {


                Console.WriteLine("name :" + name);
            }
            for (int i = 0; i < number.Length; i++)
            {
                Console.WriteLine("{0} is {1}", i, number[i]);

            }
            Console.ReadKey();
        }


    }
}
