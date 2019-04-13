// pages/search/search.js
const app = getApp();

Page({

  /**
   * 页面的初始数据
   */
  data: {
    foodName:''
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.onQuery();

  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  },
  
  onQuery: function () {
    this.setData({
      food1: app.globalData.food1,
      food1Index: app.globalData.food1Index
    })
  },

  searchFun: function(e) {
    const foodname=this.data.foodName;
    const list = this.data.food1;
    this.setData({
      foodName:foodname
    })
    for(var t in list)
    {
      console.log(t);
      if (list[t]['name'] === foodname)
      {
        this.setData({
          showRes: list[t],
          flagRes:true
        })
        break;
      }else
      {
        this.setData({
          flagRes:false
        })
      }
    }
  },

  foodchange:function(e) {
    this.data.foodName=e.detail.value;
    this.searchFun();
  }
})