// pages/record/record.js
const app = getApp()
const db = wx.cloud.database()
const _ = db.command;
Page({
  data: {
    navbar: ['记录', '秘密'],
    currentTab: 0,
    img_url1: [],
    img_url2: [],
    fileid: [],
    content1: '',
    content2: '',
    find1: 0,
    find2: 0,
    hideAdd1: 0,
    hideAdd2: 0,
    array: ['简单', '中等', '困难'],
    latitude: '',
    longitude: '',
    accuracy: '',
    id: ''
  },

  onLoad: function (options) {
    // 页面初始化 options为页面跳转所带来的参数

  },

  //输入框
  input1: function (e) {
    this.setData({
      id: app.globalData.openid,
      content1: e.detail.value,
    })
  },
  input2: function (e) {
    this.setData({
      id: app.globalData.openid,
      content2: e.detail.value,
    })
  },
  //选择图片
  chooseimage1: function () {
    var that = this;
    wx.chooseImage({
      count: 9-that.data.img_url1.length, // 默认9 
      sizeType: ['original', 'compressed'], // 可以指定是原图还是压缩图，默认二者都有 
      sourceType: ['album', 'camera'], // 可以指定来源是相册还是相机，默认二者都有 
      success: function (res) {
        if (res.tempFilePaths.length > 0) {
          //图如果满了9张，不显示加图
          if (res.tempFilePaths.length+that.data.img_url1.length == 9) {
            that.setData({
              hideAdd1: 1
            })
          } else {
            that.setData({
              hideAdd1: 0
            })
          }
          //把每次选择的图push进数组
          let img_url = that.data.img_url1;
          for (let i = 0; i < res.tempFilePaths.length; i++) {
            img_url.push(res.tempFilePaths[i])
          }
          that.setData({
            img_url1: img_url
          })
        }
      }
    })
  },
  chooseimage2: function () {
    var that = this;
    wx.chooseImage({
      count: 9-that.data.img_url2.length, // 默认9 
      sizeType: ['original', 'compressed'], // 可以指定是原图还是压缩图，默认二者都有 
      sourceType: ['album', 'camera'], // 可以指定来源是相册还是相机，默认二者都有 
      success: function (res) {
        if (res.tempFilePaths.length > 0) {
          //图如果满了9张，不显示加图
          if (res.tempFilePaths.length+that.data.img_url2.length == 9) {
            that.setData({
              hideAdd2: 1
            })
          } else {
            that.setData({
              hideAdd2: 0
            })
          }
          //把每次选择的图push进数组
          let img_url = that.data.img_url2;
          for (let i = 0; i < res.tempFilePaths.length; i++) {
            img_url.push(res.tempFilePaths[i])
          }
          that.setData({
            img_url2: img_url
          })
        }
      }
    })
  },
  //发布按钮事件
  send1: function () {
    var that = this;
    //var user_id = wx.getStorageSync('userid')
    if (that.data.content1 != '') {
      wx.showLoading({
        title: '上传中',
      })
      that.img_upload1();
    } else {
      wx.showToast({
        title: '内容不能为空哦',
      })
    }
  },
  //文本上传
  text_upload1: function () {
    var that = this;
    wx.getLocation({
      type: 'gcj02',
      success: function (res) {
        that.setData({
          latitude: res.latitude,
          longitude: res.longitude,
          accuracy: res.accuracy
        })
        db.collection("record").add({
          data: {
            content: that.data.content1,
            find: that.data.find1,
            bool: that.data.currentTab,
            length: that.data.img_url1.length,
            location: {
              latitude: that.data.latitude,
              longitude: that.data.longitude,
              accuracy: that.data.accuracy,
            },
            fileid: that.data.fileid,
            avatarUrl: app.globalData.avatarUrl,
            nickName:app.globalData.nickName
          },
          success(res) {
            wx.hideLoading();
            wx.showToast({
              title: '发布成功',
            })
          },
          fail: e => {
            wx.hideLoading();
            wx.showToast({
              title: '发布失败',
            })
          }
        })
      },
    })
  },
  //图片上传
  img_upload1: function () {
    var that = this;
    var img_url = that.data.img_url1;
    var count = 0;
    var thetime=Date.now();
    //由于图片只能一张一张地上传，所以用循环
    if(img_url.length==0)
    {
      that.text_upload1();
    }
    for (let i = 0; i < img_url.length; i++) {
      var filePath = img_url[i]
      var index1 = filePath.lastIndexOf(".");
      var index2 = filePath.length;
      var postf = filePath.substring(index1, index2);
      // 上传图片
      var cloudPath = thetime + '_'+i + '_' + that.data.id + postf
      wx.cloud.uploadFile({
        //路径填你上传图片方法的地址
        cloudPath,
        filePath,
        success: res => {
          that.data.fileid.push(res.fileID)
          if (i == img_url.length - 1) {
            that.text_upload1();
          }
        },
      })
    }
  },

  send2: function () {
    var that = this;
    //var user_id = wx.getStorageSync('userid')
    if (that.data.content2 != '') {
      wx.showLoading({
        title: '上传中',
      })
      that.img_upload2();
    } else {
      wx.showToast({
        title: '内容不能为空哦',
      })
    }
  },
  //文本上传
  text_upload2: function () {
    var that = this;
    wx.getLocation({
      type: 'gcj02',
      success: function (res) {
        that.setData({
          latitude: res.latitude,
          longitude: res.longitude,
          accuracy: res.accuracy
        })
        db.collection("record").add({
          data: {
            content: that.data.content2,
            find: that.data.find2,
            bool: that.data.currentTab,
            length: that.data.img_url2.length,
            location: {
              latitude: that.data.latitude,
              longitude: that.data.longitude,
              accuracy: that.data.accuracy,
            },
            fileid: that.data.fileid,
            avatarUrl: app.globalData.avatarUrl,
            nickName: app.globalData.nickName
          },
          success(res) {
            wx.hideLoading();
            wx.showToast({
              title: '发布成功',
            })
          },
          fail: e => {
            wx.hideLoading();
            wx.showToast({
              title: '发布失败',
            })
          }
        })
      }
    })
  },
  //图片上传
  img_upload2: function () {
    var that = this;
    var img_url = that.data.img_url2;
    var count = 0;
    var thetime = Date.now();
    //由于图片只能一张一张地上传，所以用循环
    if (img_url.length == 0) {
      that.text_upload2();
    }
    for (let i = 0; i < img_url.length; i++) {
      var filePath = img_url[i]
      var index1 = filePath.lastIndexOf(".");
      var index2 = filePath.length;
      var postf = filePath.substring(index1, index2);
      // 上传图片
      var cloudPath = thetime +'_'+ i + '_' + that.data.id + postf
      wx.cloud.uploadFile({
        //路径填你上传图片方法的地址
        cloudPath,
        filePath,
        success: res => {
          that.data.fileid.push(res.fileID)
          if (i == img_url.length - 1) {
            that.text_upload2();
          }
        },
      })
    }
  },

  clickTab: function (e) {
    var that = this;
    if (this.data.currentTab === e.target.dataset.current) {
      return false;
    } else {
      that.setData({
        currentTab: e.target.dataset.current
      })
    }
  },

  swiperTab: function (e) {
    var that = this;
    that.setData({
      currentTab: e.detail.current
    });
  },

  bindPickerChange1: function (e) {
    this.setData({
      find1: e.detail.value
    })
  },

  bindPickerChange2: function (e) {
    this.setData({
      find2: e.detail.value
    })
  },
})