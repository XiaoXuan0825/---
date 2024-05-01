# 組別號碼 : 13
# 系級班級 : 資工 1A
# 成員資訊 : 蕭芷萱 吳承翰 陳威安
# 小專題題目 : 十點半
# 程式介紹 :
### 遊戲用牌為一副牌，去除兩張鬼牌。每人發派1張牌作為手牌。玩家須透過補牌使自身牌組加總靠近十點半，並與莊家的牌組進行大小比較。
### 遊戲人數設定為2人，一名莊家（PC）以及一名玩家（Player）。
### 玩家下注，下注完後每人發一張牌，玩家與莊家比大小，輸牌便損失注金，贏牌可以向莊家索取規定倍數的獎金。
# 程式規則 :
### 牌面A=1點，2~9即為牌面點數，J、Q、K都算0.5點。
# 基本玩法 :
## * 公共規則 :
###   * 玩家初始獲得100元資金，每次注金至少10元。
###   * 若玩家資金小於或等於0元，則結束遊戲。
###   * 莊家及玩家各獲得一張手牌。
###   * 最多可以加牌至五張，若超過10.5，即為**Busted**，對手立賠1倍注金。
###   * 牌組五張以內恰好為10.5，稱**Ten-A-Half**，對手立賠2倍注金。
###   * 牌組恰好五張而未爆牌，稱**Dragon**，對手立賠3倍注金。
###   * 牌組恰好五張且點數剛好10.5，稱**Big-Dragon**，對手立賠5倍注金。
## * 玩家 :
###   * 玩家先選擇**要牌**或是**停牌**，牌組低於6時必須**要牌**。
###   * 玩家選擇**停牌**後將不可再加牌，確認玩家的牌組沒有超過10.5後輪到莊家開牌。
## * 莊家 :
###   * 若玩家已爆牌或贏牌，則結束這局遊戲，莊家不進行開牌及加牌。
###   * 當雙方停牌且牌組總和小於或等於10.5時，雙方進行大小比較，較大者勝。
###   * 若雙方點數相同則為莊家獲勝，玩家立賠1倍注金。
###   * 使用過的牌將不再使用直到結束時牌少於10張，屆時將重新洗牌。
###   * 當每局結束後，玩家可以選擇是否重新洗牌。
## 贏牌賠率 :
### * high-card : 1倍注金。
### * Busted : 1倍注金。
### * Ten-A-Half : 2倍注金。
### * Dragon : 3倍注金。
### * Big-Dragon : 5倍注金。
# 程式如何安裝執行：
# 程式畫面截圖：
# 分工資訊：
### 蕭芷萱 : README、第一次報告、PPT、主程式。
### 吳承翰 : 尚未進入github。
### 陳威安 : 已進入github。
