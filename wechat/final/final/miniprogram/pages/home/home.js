// pages/home/home.js
const app = getApp()
const db = wx.cloud.database()
const _ = db.command;

Page({
  data: {
    avatarUrl: './user-unlogin.png',
    userInfo: {},
    logged: false,
    takeSession: false,
    requestResult: '',
    nickname:'',
    sex:0,
    openid:''
  },

  onShow: function (e) {
    this.onLoad()
  },
  
  onLoad: function () {
    var that = this;
    if (app.globalData.openid && app.globalData.openid != '')    {
      this.setData({
        openid:app.globalData.openid
      })
      this.getOpenid()
    } else {
      app.openidCallback = openid => {
        if (openid != '') {
          this.setData({
            openid: app.globalData.openid
          })
          this.getOpenid()
        }
      }
    }
  },

  getOpenid:function(){
    var that=this
    db.collection('user').doc(that.data.openid + '_name_sex').get({
      success(res) {
        that.setData({
          logged: true,
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
                },
                fail:e=>{
                  wx.showToast({
                    title: '登录失败'
                  })
                }
              })
            }
          }
        })
      },
      fail(e) {
        // 获取用户信息
        wx.getSetting({
          success: res => {
            if (res.authSetting['scope.userInfo']) {
              wx.getUserInfo({
                success: res => {
                  that.setData({
                    logged: true,
                    avatarUrl: res.userInfo.avatarUrl,
                    nickname: res.userInfo.nickName,
                    sex: res.userInfo.gender
                  })
                  db.collection("user").add({
                    data: {
                      _id: that.data.openid + "_name_sex",
                      nickname: res.userInfo.nickName,
                      sex: res.userInfo.gender,
                    }
                  })
                },
                fail:e=>{
                  wx.showToast({
                    title: '登录失败'
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
    wx.navigateTo({
      url: "../mine/mine"
    })
  },

  /** 转到记录页**/
  moveToRecord: function(e) {
    wx.navigateTo({
      url: '../record/record',
    })
  },

  /** 转到探索页**/
  moveToSearch: function(e) {
    wx.navigateTo({
      url: '../search/search',
    })
  }


})