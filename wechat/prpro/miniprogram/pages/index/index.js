//index.js
//获取应用实例
const app = getApp()
var wxCharts = require('../../utils/wxcharts.js');
var columnChart = null;
var chartData = {
  main: {
    title: '摄入指标',
    data: [1200, 198, 24, 34.67,300,22],
    categories: ['能量', '碳水化合物', '蛋白质', '脂肪' ,'胆固醇' , '膳食纤维']
  }
};
var data0=0;  //输出柱状图单位

Page({
  data: {
    userInfo: {},
    hasUserInfo: false,
    hasOpenId: false,
    canIUse: wx.canIUse('button.open-type.getUserInfo'),
    headlthNumber: [1,2,3,4,5],
    fristInformation:false,
    psData: {
      name:'',
      old: '',
      height: '',
      weight: '',
      diseaseName:'',
      diseaseOld:''
    },pslog: {
      title: '',
      content: '',
      hidden: true
    }
  },
  //事件处理函数
  bindViewTap: function() {
    wx.navigateTo({
      url: '../logs/logs'
    })
  },
  onLoad: function () {
    if (!wx.cloud) {
      wx.redirectTo({
        url: '../chooseLib/chooseLib',
      })
      return
    }
    if (app.globalData.userInfo) {
      this.setData({
        userInfo: app.globalData.userInfo,
        hasUserInfo: true
      })
      //同步获取用户数据
      this.onGetOpenid();
    } else if (this.data.canIUse){
      // 由于 getUserInfo 是网络请求，可能会在 Page.onLoad 之后才返回
      // 所以此处加入 callback 以防止这种情况
      app.userInfoReadyCallback = res => {
        this.setData({
          userInfo: res.userInfo,
          hasUserInfo: true
        })
        //同步获取用户数据
        this.onGetOpenid();
      }
    } else {
      // 在没有 open-type=getUserInfo 版本的兼容处理
      wx.getUserInfo({
        success: res => {
          app.globalData.userInfo = res.userInfo
          this.setData({
            userInfo: res.userInfo,
            hasUserInfo: true
          })
        }
      })
      //同步获取用户数据
      this.onGetOpenid();
    }
  },
  getUserInfo: function(e) {
    console.log(e)
    app.globalData.userInfo = e.detail.userInfo
    this.setData({
      userInfo: e.detail.userInfo,
      hasUserInfo: true
    })
    this.onGetOpenid();
  },
  onReady: function (e) {
    var windowWidth = 320;
    try {
      var res = wx.getSystemInfoSync();
      windowWidth = res.windowWidth;
    } catch (e) {
      console.error('getSystemInfoSync failed!');
    }

    columnChart = new wxCharts({
      canvasId: 'columnCanvas',
      type: 'column',
      animation: true,  //是否动画显示
      categories: chartData.main.categories,  // (饼图、圆环图不需要) 数据类别分类
      legend:false,
      series: [{
        color: '#f5bda4',
        name: '指标',
        data: chartData.main.data,
        format: function (val, name) {
          var temp = 'g';
          if(!data0)
            temp = 'kcal';
          if(data0===4)
            temp = 'mg';
          data0 = data0 + 1;
          if(data0===6)
            data0=0;
          return val.toFixed(2) + temp;
        }
      }],
      yAxis: {
        disabled :true
      },
      xAxis: {
        disableGrid: false,
        type: 'calibration'
      },
      extra: {
        column: {
          width: 30
        }
      },
      width: windowWidth,
      height: 200
    });
  },
  namechange(e) {
    this.data.psData.name = e.detail.value;
  },
  oldchange(e) {
    this.data.psData.old = e.detail.value;
  },
  heightchange(e) {
    this.data.psData.height = e.detail.value;
  },
  weightchange(e) {
    this.data.psData.weight = e.detail.value;
  },
  diseaseNamechange(e) {
    this.data.psData.diseaseName = e.detail.value;
  },
  diseaseOldchange(e) {
    this.data.psData.diseaseOld = e.detail.value;
  },
  submitData: function (event) {
    const psData = this.data.psData;
    if(psData.name.length === 0) {
      this.setData({
        psData,
        'pslog.hidden':false,
        'pslog.title':'数据保存失败',
        'pslog.content':'姓名不能为空'
      })
    } else if(psData.old.length ===0) {
      this.setData({
        psData,
        'pslog.hidden': false,
        'pslog.title': '数据保存失败',
        'pslog.content': '年龄不能为空'
      })
    } else if (psData.height.length === 0) {
      this.setData({
        psData,
        'pslog.hidden': false,
        'pslog.title': '数据保存失败',
        'pslog.content': '身高不能为空'
      })
    } else if (psData.weight.length === 0) {
      this.setData({
        psData,
        'pslog.hidden': false,
        'pslog.title': '数据保存失败',
        'pslog.content': '体重不能为空'
      })
    } else if (psData.diseaseName.length === 0) {
      this.setData({
        psData,
        'pslog.hidden': false,
        'pslog.title': '数据保存失败',
        'pslog.content': '病名不能为空'
      })
    } else if (psData.diseaseOld.length === 0) {
      this.setData({
        psData,
        'pslog.hidden': false,
        'pslog.title': '数据保存失败',
        'pslog.content': '病龄不能为空'
      })
    } else {
      this.setData({
        psData,
        'pslog.hidden': false,
        'pslog.title': '数据保存成功',
        'pslog.content': '数据保存成功',
        fristInformation:true
      })
      //存储到全局
      app.globalData.psData=this.data.psData;
      this.onAdd();
    }
  }, 
  confirm() {
    this.setData({
      'pslog.hidden': true,
      'pslog.title': '',
      'pslog.content': ''
    })
  },
  onGetOpenid: function () {
    // 调用云函数
    wx.cloud.callFunction({
      name: 'user',
      data: {},
      success: res => {
        console.log(res);
        console.log('[云函数] [login] user openid: ', res.result.openid)
        app.globalData.openid = res.result.openid
        this.setData({
          hasOpenId: true
        })
        this.onQuery();
      },
      fail: err => {
        console.error('[云函数] [login] 调用失败', err)
      }
    })
  },
  onAdd: function() {
    const db = wx.cloud.database();
    db.collection('user').add({
      data:{
        psData: this.data.psData,
      },
      success: res => {
        // 在返回结果中会包含新创建的记录的 _id
        this.setData({
          counterId: res._id,
        })
        wx.showToast({
          title: '新增记录成功',
        })
        console.log('[数据库] [新增记录] 成功，记录 _id: ', res._id)
      },
      fail: err => {
        wx.showToast({
          icon: 'none',
          title: '新增记录失败'
        })
        console.error('[数据库] [新增记录] 失败：', err)
      }
    })
  },
  onQuery: function () {
    const db = wx.cloud.database()
    // 查询当前用户所有的 user
    db.collection('user').where({
      _openid: this.data.openid
    }).get({
      success: res => {
        var temp = res.data;
        if(temp.length > 0 )
        {
          this.setData({
            psData: temp[0].psData,
            fristInformation:true
          })
          //存储到全局
          app.globalData.psData = this.data.psData;
        }
        console.log('[数据库] [查询记录] 成功: ', res)
      },
      fail: err => {
        wx.showToast({
          icon: 'none',
          title: '查询记录失败'
        })
        console.error('[数据库] [查询记录] 失败：', err)
      }
    })
    wx.cloud.callFunction({
      name: 'getFood1',
      data: {},
      success: res => {
        console.log(res);
        var index = Object.keys(res.result.data[0]);
        this.setData({
          food1: res.result.data,
          food1Index: index
        })
        app.globalData.food1 = this.data.food1;
        app.globalData.food1Index=this.data.food1Index;
      },
      fail: err => {
        console.error('[云函数] [login] 调用失败', err);
      }
    })
  },
})
