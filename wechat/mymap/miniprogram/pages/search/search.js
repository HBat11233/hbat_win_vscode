// pages/search/search.js

const app = getApp()

Page({

  /**
   * 页面的初始数据
   */
  data: {
    latitude:'',
    longitude:'',
    speed:'',
    accuracy:'',
    cardx:50,
    cardy:50
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) {
    this.updataLocation();
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

  /**
   * 刷新位置信息
   */
  updataLocation: function() {
    wx.getLocation({
      type: 'gcj02',
      altitude: true,
      success: res => {
        const latitude = res.latitude
        const longitude = res.longitude
        this.setData({
          latitude:res.latitude,
          longitude:res.longitude,
          speed:res.speed,
          accuracy:res.accuracy,
          altitude:res.altitude,
          markers:[{
            iconPath:'/ico/ddw.png',
            id: 0,
            latitude: res.latitude,
            longitude: res.longitude,
            width: 25,
            height: 25
          }],
          circles:[{
            latitude:res.latitude,
            longitude:res.longitude,
            radius:res.accuracy,
            fillColor: '#0000ff'
          }]
        })
      this.onGetData()
      }
    })
  },

  onGetData: function () {
    // 调用云函数
    wx.cloud.callFunction({
      name: 'getcard',
      data: {},
      success: res => {
        console.log('data size: ', res.result.data.length)
        var tempimpath={}
        for(var i=0;i<res.result.data.length;++i)
        {
          var temp={
            iconPath:'/ico/ddw.png',
            id: i+1,
            latitude: res.result.data[i].location.latitude,
            longitude: res.result.data[i].location.longitude,
            width: 25,
            height: 25
          }
          //console.log(res.result.data[i].location)
          wx.cloud.getTempFileURL({
            fileList:res.result.data[i].fileid,
            success: res => {
              console.log('图片获取成功')
              for(var k=0;k<res.fileList.length;++k)
                tempimpath[res.fileList[k].fileID]=res.fileList[k].tempFileURL
              this.setData({
                tempimpath:tempimpath
              })
              //console.log('gettempfileurl',tempimpath)
            },
            fail: err => {
              console.log('图片获取失败')
            }
          })
          this.data.markers.push(temp)
          //console.log('callfuncation:',tempimpath)
        }
        var temp=this.data.markers
        //console.log(temp)
        this.setData({
          markers:temp,
          clouddata:res.result
        })

        //app.globalData.openid = res.result.openid
        //wx.navigateTo({
        //  url: '../userConsole/userConsole',
        //})
      },
      fail: err => {
        console.error('[云函数] [login] 调用失败', err)
        //wx.navigateTo({
        //  url: '../deployFunctions/deployFunctions',
        //})
      }
    })
  },

  toimage: function (res) {
    app.globalData.imageid=res.currentTarget.id;
  }
})