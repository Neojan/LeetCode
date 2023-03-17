/*
汇率如下表
即100CNY=1825JPY=123HKD=14EUR=12GBP

输入描述：
第一行输入为N，N表示记录数。0<N<100
之后N行，每行表示一条货币记录，且该行只会是一种货币。
输出描述：
将每行货币转换成人民币分（fen）后汇总求和，只保留整数部分。
输出格式只有整数数字，不带小数，不带单位。
补充说明：
输出格式只有数字，不带单位

示例1
输入：
1
100CNY
输出：
10000
说明：
100CNY转换后是10000fen，所以输出结果为10000

示例2
输入：
1
3000fen
输出：
3000
说明：
3000fen，结果就是3000
示例3
输入：
1
123HKD
输出：
10000
说明：
HKD与CNY的汇率关系是123:100，所以换算后，输出结果为10000
示例4
输入：
2
20CNY53fen
53HKD87cents
输出：
6432
说明：
20元53分+53港元87港分，换算成人民币分后汇总，为6432

解题思路： 因为5种货币的首字母不相同，所以可以将其作为货币的标识来进行换算。

计算的时候需要使用double类型，否则会出问题。
*/


import java.util.*;

public
class Main {


public
    static void main(String[] args)
    {
        Scanner in  = new Scanner(System.in);
        int     n   = in.nextInt();
        int     sum = 0;
        in.nextLine();
        for (int i = 0; i < n; i++)
        {
            sum += getNum(in.nextLine());
        }
        System.out.println(sum);
    }

    /**
     * 拆分数字和单位
     * @param numStr
     * @author: lenovo
     * @date: 2023/02/18 23:08
     * @return: double
     */
    static double getNum(String numStr)
    {
        String val = "";
        double num = 0;
        for (int i = 0; i < numStr.length(); i++)
        {
            char x = numStr.charAt(i);
            if (Character.isDigit(x))
            {
                val += x;
            }
            else
            {
                if (val.equals(""))
                {
                    continue;
                }

                num += turn(val, x);
                i += 2;
                val = "";
            }
        }
        return num;
    }

    /**
     * 计算
     *
     * @param numStr
     * @param str
     * @author: lenovo
     * @date: 2023/02/18 23:07
     * @return: double
     */
    static double turn(String numStr, char str)
    {
        double sum = 0;
        int    num = Integer.valueOf(numStr);
        if (str == 'C')
        {
            sum = num * 100;
        }
        else if (str == 'J')
        {
            sum = (double)num * 10000 / 1825;
        }
        else if (str == 'H')
        {
            sum = (double)num * 10000 / 123;
        }
        else if (str == 'E')
        {
            sum = (double)num * 10000 / 14;
        }
        else if (str == 'G')
        {
            sum = (double)num * 10000 / 12;
        }
        else if (str == 'f')
        {
            sum = num * 1;
        }
        else if (str == 's')
        {
            sum = (double)num * 100 / 1825;
        }
        else if (str == 'c')
        {
            sum = (double)num * 100 / 123;
        }
        else if (str == 'e')
        {
            sum = (double)num * 100 / 14;
        }
        else if (str == 'p')
        {
            sum = (double)num * 100 / 12;
        }
        return sum;
    }
}
