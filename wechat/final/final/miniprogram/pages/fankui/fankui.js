const app = getApp()
const db = wx.cloud.database()
const _ = db.command;
Page({
  data: {
    title: '',
    phone: '',
    content: '',
    id: ''
  },

  title: function(e) {
    this.setData({
      title: e.detail.value
    })
  },

  phone: function(e) {
    this.setData({
      phone: e.detail.value
    })
  },

  content: function(e) {
    this.setData({
      content: e.detail.value
    })
  },

  upload: function(e) {
    var that = this
    if (that.data.title != '' && that.data.content != '') {
      db.collection("fankui").add({
        data: {
          title: that.data.title,
          phone: that.data.phone,
          content: that.data.content
        },
        success(res){
          wx.showToast({
            title: '谢谢您的反馈',
          })
        }
      })
    }
    else{
      wx.showToast({
        title: '标题和内容不能为空',
      })
    }
  }
})