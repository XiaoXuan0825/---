# 組別號碼 : 13
# 系級班級 : 資工 1A
# 成員資訊 : 蕭芷萱 吳承翰 陳威安
# 小專題題目 : 十點半
# 程式介紹 :
### 遊戲用牌為一副牌，去除兩張鬼牌。每人隨機發1張牌作為手牌，一名莊家(電腦)及一個玩家。玩家須透過補牌使自身牌組加總靠近或等於十點半，並與莊家的牌組進行大小比較。
# 程式規則 :
### 牌面A=1點，2~9即為牌面點數，J、Q、K都算0.5點。
## 基本玩法 :
* 玩家 :
  * 莊家及玩家各獲得一張手牌。
  * 玩家先選擇**要牌**或是**停牌**，牌組低於6時必須要牌。
  * 玩家最多可以加牌至五張，若超過10.5，即為**Busted**，玩家立賠。
  * 牌組恰好為10.5，稱**Ten-A-Half**，莊家立賠。
  * 玩家的牌組恰好五張而未爆牌，稱**Dragon**，莊家立賠。
  * 玩家的牌組恰好五張且點數剛好10.5，稱**Big-Dragon**，莊家立賠。
* 莊家 :
 * 玩家選擇**停牌**後將不可再加牌，確認玩家的牌組沒有超過10.5後輪到莊家開牌。(若玩家已爆牌或贏牌，則結束這局遊戲，莊家不進行開牌及加牌。)
* 莊家規則與上述相同，當莊家也停牌後，雙方進行大小比較，較大者勝。若雙方點數相同則為莊家獲勝，玩家立賠。  
## 贏牌賠率 :
*
# 程式玩法 : 
### 遊戲人數設定為2人，一名莊家（PC）以及一名玩家（Player）。
### 由玩家先下注，下注完後每人發一張牌，每個玩家與莊家各自比大小，輸牌便損失注金，贏牌可以向莊家索取規定倍數的獎金。
