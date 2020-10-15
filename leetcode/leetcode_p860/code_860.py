# 力扣第860题，柠檬水找零
"""
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。

顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

如果你能给每位顾客正确找零，返回 true ，否则返回 false .
"""

class Solution:
    def lemonadeChange(self, bills):
        wallet = dict()
        for bill in bills:
            if bill == 5:
                wallet[bill] = wallet.get(bill, 0) + 1
            if bill == 10:
                wallet[5] = wallet.get(5, 0) - 1
                wallet[bill] = wallet.get(bill, 0) + 1
            if bill == 20:
                if wallet.get(10, 0) != 0:
                    wallet[10] -= 1
                    wallet[5] = wallet.get(5, 0) - 1 
                else:
                    wallet[5] = wallet.get(5, 0) - 3
            if wallet.get(5, 0) < 0:
                return False
        else:
            return True


if __name__ == "__main__":
    bills = [5, 5, 5, 10, 20]
    
