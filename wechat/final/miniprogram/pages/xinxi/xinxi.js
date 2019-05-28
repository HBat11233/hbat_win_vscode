const app = getApp()
const db = wx.cloud.database()
const _ = db.command;

Page({
  data: {
    nickname: '',
    sex: 0,
    array: [" ","男", "女"],
  },

  onLoad: function (e) {
    var that=this;
    db.collection('user').doc(app.globalData.openid+'_name_sex').get({
      success(res) {
        that.setData({
          nickname: res.data.nickname,
          sex:res.data.sex
        })
      }
    })
  },

  getValue:function(e){
    this.setData({
      nickname: e.detail.value
    })
  },

  bindPickerChange: function (e) {
    this.setData({
      sex: e.detail.value
    })
  },

  /*上传信息*/
  push: function (e) {
    if (this.data.nickname&&this.data.sex) {
      db.collection('user').doc(app.globalData.openid+"_name_sex").update({
        data:{
          nickname: this.data.nickname,
          sex: this.data.sex,
        },
        success: res => {
          wx.showToast({
            title: '发布成功',
          })
        },
        fail: e => {
          wx.showToast({
            title: '发布错误',
          })
        }
      })
    } else {
      wx.showToast({
        title: '请填写文字',
        icon: 'none'
      })
    }
  },
})