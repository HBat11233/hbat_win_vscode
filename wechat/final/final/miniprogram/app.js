//app.js
App({
  onLaunch: function() {
    if (!wx.cloud) {
      console.error('请使用 2.2.3 或以上的基础库以使用云能力')
    } else {
      wx.cloud.init({
        traceUser: true,
      })
    }
    this.globalData = {}
    var that = this;
    // 登录
    wx.login({
      success: res => {
        wx.cloud.callFunction({
          name: 'login',
          data: {},
          success: function(res) {
            that.globalData.openid = res.result.openid;
            if (that.openidCallback) {
              that.openidCallback(res.result.data);
            }
          }
        })
      }
    })
  },
  getLocation:function(){
    wx.getLocation({
      type: 'wgs84',
      success: function(res) {
        this.globalData.latitude = res.latitude
        this.globalData.longitude = res.longitude
        this.globalData.accuracy = res.accuracy
      },
    })
  }
})