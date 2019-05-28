// pages/mine/mine.js
// pages/home/home.js
const app = getApp()
const db = wx.cloud.database()
const _ = db.command;

Page({
  data: {
    avatarUrl: '../home/user-unlogin.png',
    userInfo: {},
    name: '',
    logged: false,
    takeSession: false,
    requestResult: '',
    openid:''
  },

  onShow: function(e) {
    this.onLoad()
  },

  onLoad: function(e) {
    this.setData({
      openid:app.globalData.openid
    })
    //获取云端信息
    var that = this;
    db.collection('user').doc(that.data.openid+'_name_sex').get({
      success(res) {
        that.setData({
          nickname: res.data.nickname,
        })
        wx.getSetting({
          success: res => {
            if (res.authSetting['scope.userInfo']) {
              wx.getUserInfo({
                success: res => {
                  that.setData({
                    avatarUrl: res.userInfo.avatarUrl,
                  })
                }
              })
            }
          }
        })
      }
    })
  },

  onGetUserInfo: function(e) {
    if (!this.logged && e.detail.userInfo) {
      this.setData({
        logged: true,
        avatarUrl: e.detail.userInfo.avatarUrl,
        userInfo: e.detail.userInfo
      })
    }
  },

  xinxi: function(e) {
    wx.navigateTo({
      url: '/pages/xinxi/xinxi',
    })
  },

  fankui: function(e) {
    wx.navigateTo({
      url: '../fankui/fankui',
    })
  },

  bangzhu: function(e) {
    wx.navigateTo({
      url: '/pages/bangzhu/bangzhu',
    })
  }
})