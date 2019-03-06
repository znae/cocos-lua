//
// generated by tolua
//
#include "xgame/lua-bindings/lua_xgame.h"
#include "xgame/lua-bindings/lua_conv.h"
#include "xgame/xfilesystem.h"
#include "xgame/xlua-conv.h"
#include "xgame/xlua.h"
#include "xgame/xpreferences.h"
#include "xgame/xruntime.h"
#include "xgame/xtimer.h"
#include "tolua/tolua.hpp"

static int _xgame_runtime_clearStorage(lua_State *L)
{
    lua_settop(L, 0);

    xgame::runtime::clearStorage();

    return 0;
}

static int _xgame_runtime_launch(lua_State *L)
{
    lua_settop(L, 1);

    std::string arg1;

    tolua_check_std_string(L, 1, &arg1);

    bool ret = (bool)xgame::runtime::launch(arg1);

    return tolua_push_bool(L, ret);
}

static int _xgame_runtime_restart(lua_State *L)
{
    lua_settop(L, 0);

    bool ret = (bool)xgame::runtime::restart();

    return tolua_push_bool(L, ret);
}

static int _xgame_runtime_isRestarting(lua_State *L)
{
    lua_settop(L, 0);

    bool ret = (bool)xgame::runtime::isRestarting();

    return tolua_push_bool(L, ret);
}

static int _xgame_runtime_setAntialias(lua_State *L)
{
    lua_settop(L, 2);

    bool arg1 = false;
    lua_Unsigned arg2 = 0;

    tolua_check_bool(L, 1, &arg1);
    tolua_check_uint(L, 2, &arg2);

    xgame::runtime::setAntialias(arg1, (unsigned int)arg2);

    return 0;
}

static int _xgame_runtime_isAntialias(lua_State *L)
{
    lua_settop(L, 0);

    bool ret = (bool)xgame::runtime::isAntialias();

    return tolua_push_bool(L, ret);
}

static int _xgame_runtime_getNumSamples(lua_State *L)
{
    lua_settop(L, 0);

    unsigned int ret = (unsigned int)xgame::runtime::getNumSamples();

    return tolua_push_uint(L, (lua_Unsigned)ret);
}

static int _xgame_runtime_canOpenURL(lua_State *L)
{
    lua_settop(L, 1);

    std::string arg1;

    tolua_check_std_string(L, 1, &arg1);

    bool ret = (bool)xgame::runtime::canOpenURL(arg1);

    return tolua_push_bool(L, ret);
}

static int _xgame_runtime_support(lua_State *L)
{
    lua_settop(L, 1);

    std::string arg1;

    tolua_check_std_string(L, 1, &arg1);

    bool ret = (bool)xgame::runtime::support(arg1);

    return tolua_push_bool(L, ret);
}

static int _xgame_runtime_printSupport(lua_State *L)
{
    lua_settop(L, 0);

    xgame::runtime::printSupport();

    return 0;
}

static int _xgame_runtime_disableReport(lua_State *L)
{
    lua_settop(L, 0);

    xgame::runtime::disableReport();

    return 0;
}

static int _xgame_runtime_setDispatcher(lua_State *L)
{
    int handler = xlua_reffunc(L, 1);
    xgame::runtime::setDispatcher([handler](const std::string &event, const std::string &args) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, handler);
        if (lua_isfunction(L, -1)) {
            lua_pushstring(L, event.c_str());
            lua_pushstring(L, args.c_str());
            lua_pcall(L, 2, 0, top + 1);
        }
        lua_settop(L, top);
    });
    return 0;
}

static int _xgame_runtime_openURL(lua_State *L)
{
    lua_settop(L, 2);
    int callback = LUA_REFNIL;
    if (lua_isfunction(L, 2)) {
        callback = xlua_reffunc(L, 2);
    }
    xgame::runtime::openURL(luaL_checkstring(L, 1), [callback](bool success) {
        if (callback != LUA_REFNIL) {
            lua_State *L = xlua_cocosthread();
            int top = lua_gettop(L);
            lua_pushcfunction(L, xlua_errorfunc);
            xlua_getref(L, callback);
            if (lua_isfunction(L, -1)) {
                lua_pushboolean(L, success);
                lua_pcall(L, 1, 0, top + 1);
                xlua_unref(L, callback);
            }
            lua_settop(L, top);
        }
    });
    return 0;
}

static int _xgame_runtime_getPackageName(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::runtime::getPackageName();

    return tolua_push_std_string(L, ret);
}

static int _xgame_runtime_getVersion(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::runtime::getVersion();

    return tolua_push_std_string(L, ret);
}

static int _xgame_runtime_getVersionBuild(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::runtime::getVersionBuild();

    return tolua_push_std_string(L, ret);
}

static int _xgame_runtime_getChannel(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::runtime::getChannel();

    return tolua_push_std_string(L, ret);
}

static int _xgame_runtime_getOS(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::runtime::getOS();

    return tolua_push_std_string(L, ret);
}

static int _xgame_runtime_getDeviceInfo(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::runtime::getDeviceInfo();

    return tolua_push_std_string(L, ret);
}

static int _xgame_runtime_getLogPath(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::runtime::getLogPath();

    return tolua_push_std_string(L, ret);
}

static int _xgame_runtime_setLogPath(lua_State *L)
{
    lua_settop(L, 1);

    std::string arg1;

    tolua_check_std_string(L, 1, &arg1);

    xgame::runtime::setLogPath(arg1);

    return 0;
}

static int luaopen_xgame_runtime(lua_State *L)
{
    toluacls_class(L, "kernel.runtime", nullptr);
    toluacls_setfunc(L, "clearStorage", _xgame_runtime_clearStorage);
    toluacls_setfunc(L, "launch", _xgame_runtime_launch);
    toluacls_setfunc(L, "restart", _xgame_runtime_restart);
    toluacls_setfunc(L, "isRestarting", _xgame_runtime_isRestarting);
    toluacls_setfunc(L, "setAntialias", _xgame_runtime_setAntialias);
    toluacls_setfunc(L, "isAntialias", _xgame_runtime_isAntialias);
    toluacls_setfunc(L, "getNumSamples", _xgame_runtime_getNumSamples);
    toluacls_setfunc(L, "canOpenURL", _xgame_runtime_canOpenURL);
    toluacls_setfunc(L, "support", _xgame_runtime_support);
    toluacls_setfunc(L, "printSupport", _xgame_runtime_printSupport);
    toluacls_setfunc(L, "disableReport", _xgame_runtime_disableReport);
    toluacls_setfunc(L, "setDispatcher", _xgame_runtime_setDispatcher);
    toluacls_setfunc(L, "openURL", _xgame_runtime_openURL);
    toluacls_property(L, "packageName", _xgame_runtime_getPackageName, nullptr);
    toluacls_property(L, "version", _xgame_runtime_getVersion, nullptr);
    toluacls_property(L, "versionBuild", _xgame_runtime_getVersionBuild, nullptr);
    toluacls_property(L, "channel", _xgame_runtime_getChannel, nullptr);
    toluacls_property(L, "os", _xgame_runtime_getOS, nullptr);
    toluacls_property(L, "deviceInfo", _xgame_runtime_getDeviceInfo, nullptr);
    toluacls_property(L, "logPath", _xgame_runtime_getLogPath, _xgame_runtime_setLogPath);

    toluacls_createclassproxy(L);

    return 1;
}

static int _xgame_filesystem_shortPath(lua_State *L)
{
    lua_settop(L, 2);

    std::string arg1;
    lua_Unsigned arg2 = 0;

    tolua_check_std_string(L, 1, &arg1);
    tolua_opt_uint(L, 2, &arg2, 60);

    const std::string ret = (const std::string)xgame::filesystem::shortPath(arg1, (size_t)arg2);

    return tolua_push_std_string(L, ret);
}

static int _xgame_filesystem_createDirectory(lua_State *L)
{
    lua_settop(L, 2);

    std::string arg1;
    bool arg2 = false;

    tolua_check_std_string(L, 1, &arg1);
    tolua_opt_bool(L, 2, &arg2, false);

    bool ret = (bool)xgame::filesystem::createDirectory(arg1, arg2);

    return tolua_push_bool(L, ret);
}

static int _xgame_filesystem_remove(lua_State *L)
{
    lua_settop(L, 1);

    std::string arg1;

    tolua_check_std_string(L, 1, &arg1);

    bool ret = (bool)xgame::filesystem::remove(arg1);

    return tolua_push_bool(L, ret);
}

static int _xgame_filesystem_exist(lua_State *L)
{
    lua_settop(L, 1);

    std::string arg1;

    tolua_check_std_string(L, 1, &arg1);

    bool ret = (bool)xgame::filesystem::exist(arg1);

    return tolua_push_bool(L, ret);
}

static int _xgame_filesystem_isFile(lua_State *L)
{
    lua_settop(L, 1);

    std::string arg1;

    tolua_check_std_string(L, 1, &arg1);

    bool ret = (bool)xgame::filesystem::isFile(arg1);

    return tolua_push_bool(L, ret);
}

static int _xgame_filesystem_isDirectory(lua_State *L)
{
    lua_settop(L, 1);

    std::string arg1;

    tolua_check_std_string(L, 1, &arg1);

    bool ret = (bool)xgame::filesystem::isDirectory(arg1);

    return tolua_push_bool(L, ret);
}

static int _xgame_filesystem_rename(lua_State *L)
{
    lua_settop(L, 2);

    std::string arg1;
    std::string arg2;

    tolua_check_std_string(L, 1, &arg1);
    tolua_check_std_string(L, 2, &arg2);

    bool ret = (bool)xgame::filesystem::rename(arg1, arg2);

    return tolua_push_bool(L, ret);
}

static int _xgame_filesystem_copy(lua_State *L)
{
    lua_settop(L, 2);

    std::string arg1;
    std::string arg2;

    tolua_check_std_string(L, 1, &arg1);
    tolua_check_std_string(L, 2, &arg2);

    bool ret = (bool)xgame::filesystem::copy(arg1, arg2);

    return tolua_push_bool(L, ret);
}

static int _xgame_filesystem_write(lua_State *L)
{
    lua_settop(L, 3);

    std::string arg1;
    const char *arg2 = nullptr;
    lua_Unsigned arg3 = 0;

    tolua_check_std_string(L, 1, &arg1);
    tolua_check_string(L, 2, &arg2);
    tolua_check_uint(L, 3, &arg3);

    bool ret = (bool)xgame::filesystem::write(arg1, arg2, (size_t)arg3);

    return tolua_push_bool(L, ret);
}

static int _xgame_filesystem_read(lua_State *L)
{
    lua_settop(L, 1);

    std::string arg1;

    tolua_check_std_string(L, 1, &arg1);

    cocos2d::Data ret = (cocos2d::Data)xgame::filesystem::read(arg1);

    return xluacv_push_ccdata(L, ret);
}

static int _xgame_filesystem_unzip(lua_State *L)
{
    lua_settop(L, 2);

    std::string arg1;
    std::string arg2;

    tolua_check_std_string(L, 1, &arg1);
    tolua_check_std_string(L, 2, &arg2);

    bool ret = (bool)xgame::filesystem::unzip(arg1, arg2);

    return tolua_push_bool(L, ret);
}

static int _xgame_filesystem_getWritablePath(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::filesystem::getWritablePath();

    return tolua_push_std_string(L, ret);
}

static int _xgame_filesystem_getCacheDirectory(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::filesystem::getCacheDirectory();

    return tolua_push_std_string(L, ret);
}

static int _xgame_filesystem_getDocumentDirectory(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::filesystem::getDocumentDirectory();

    return tolua_push_std_string(L, ret);
}

static int _xgame_filesystem_getTmpDirectory(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::filesystem::getTmpDirectory();

    return tolua_push_std_string(L, ret);
}

static int _xgame_filesystem_getSDCardDirectory(lua_State *L)
{
    lua_settop(L, 0);

    const std::string ret = (const std::string)xgame::filesystem::getSDCardDirectory();

    return tolua_push_std_string(L, ret);
}

static int luaopen_xgame_filesystem(lua_State *L)
{
    toluacls_class(L, "kernel.filesystem", nullptr);
    toluacls_setfunc(L, "shortPath", _xgame_filesystem_shortPath);
    toluacls_setfunc(L, "createDirectory", _xgame_filesystem_createDirectory);
    toluacls_setfunc(L, "remove", _xgame_filesystem_remove);
    toluacls_setfunc(L, "exist", _xgame_filesystem_exist);
    toluacls_setfunc(L, "isFile", _xgame_filesystem_isFile);
    toluacls_setfunc(L, "isDirectory", _xgame_filesystem_isDirectory);
    toluacls_setfunc(L, "rename", _xgame_filesystem_rename);
    toluacls_setfunc(L, "copy", _xgame_filesystem_copy);
    toluacls_setfunc(L, "write", _xgame_filesystem_write);
    toluacls_setfunc(L, "read", _xgame_filesystem_read);
    toluacls_setfunc(L, "unzip", _xgame_filesystem_unzip);
    toluacls_property(L, "writablePath", _xgame_filesystem_getWritablePath, nullptr);
    toluacls_property(L, "cacheDirectory", _xgame_filesystem_getCacheDirectory, nullptr);
    toluacls_property(L, "documentDirectory", _xgame_filesystem_getDocumentDirectory, nullptr);
    toluacls_property(L, "tmpDirectory", _xgame_filesystem_getTmpDirectory, nullptr);
    toluacls_property(L, "sdCardDirectory", _xgame_filesystem_getSDCardDirectory, nullptr);

    toluacls_createclassproxy(L);

    return 1;
}

static int _xgame_preferences_getBoolean(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    bool arg2 = false;

    tolua_check_string(L, 1, &arg1);
    tolua_opt_bool(L, 2, &arg2, false);

    bool ret = (bool)xgame::preferences::getBoolean(arg1, arg2);

    return tolua_push_bool(L, ret);
}

static int _xgame_preferences_setBoolean(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    bool arg2 = false;

    tolua_check_string(L, 1, &arg1);
    tolua_check_bool(L, 2, &arg2);

    xgame::preferences::setBoolean(arg1, arg2);

    return 0;
}

static int _xgame_preferences_getFloat(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    lua_Number arg2 = 0;

    tolua_check_string(L, 1, &arg1);
    tolua_opt_number(L, 2, &arg2, 0);

    float ret = (float)xgame::preferences::getFloat(arg1, (float)arg2);

    return tolua_push_number(L, (lua_Number)ret);
}

static int _xgame_preferences_setFloat(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    lua_Number arg2 = 0;

    tolua_check_string(L, 1, &arg1);
    tolua_check_number(L, 2, &arg2);

    xgame::preferences::setFloat(arg1, (float)arg2);

    return 0;
}

static int _xgame_preferences_getDouble(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    lua_Number arg2 = 0;

    tolua_check_string(L, 1, &arg1);
    tolua_opt_number(L, 2, &arg2, 0);

    double ret = (double)xgame::preferences::getDouble(arg1, (double)arg2);

    return tolua_push_number(L, (lua_Number)ret);
}

static int _xgame_preferences_setDouble(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    lua_Number arg2 = 0;

    tolua_check_string(L, 1, &arg1);
    tolua_check_number(L, 2, &arg2);

    xgame::preferences::setDouble(arg1, (double)arg2);

    return 0;
}

static int _xgame_preferences_getInteger(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    lua_Integer arg2 = 0;

    tolua_check_string(L, 1, &arg1);
    tolua_opt_int(L, 2, &arg2, 0);

    int ret = (int)xgame::preferences::getInteger(arg1, (int)arg2);

    return tolua_push_int(L, (lua_Integer)ret);
}

static int _xgame_preferences_setInteger(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    lua_Integer arg2 = 0;

    tolua_check_string(L, 1, &arg1);
    tolua_check_int(L, 2, &arg2);

    xgame::preferences::setInteger(arg1, (int)arg2);

    return 0;
}

static int _xgame_preferences_getString(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    const char *arg2 = nullptr;

    tolua_check_string(L, 1, &arg1);
    tolua_opt_string(L, 2, &arg2, "");

    std::string ret = (std::string)xgame::preferences::getString(arg1, arg2);

    return tolua_push_std_string(L, ret);
}

static int _xgame_preferences_setString(lua_State *L)
{
    lua_settop(L, 2);

    const char *arg1 = nullptr;
    const char *arg2 = nullptr;

    tolua_check_string(L, 1, &arg1);
    tolua_check_string(L, 2, &arg2);

    xgame::preferences::setString(arg1, arg2);

    return 0;
}

static int _xgame_preferences_deleteKey(lua_State *L)
{
    lua_settop(L, 1);

    const char *arg1 = nullptr;

    tolua_check_string(L, 1, &arg1);

    xgame::preferences::deleteKey(arg1);

    return 0;
}

static int _xgame_preferences_flush(lua_State *L)
{
    lua_settop(L, 0);

    xgame::preferences::flush();

    return 0;
}

static int luaopen_xgame_preferences(lua_State *L)
{
    toluacls_class(L, "kernel.preferences", nullptr);
    toluacls_setfunc(L, "getBoolean", _xgame_preferences_getBoolean);
    toluacls_setfunc(L, "setBoolean", _xgame_preferences_setBoolean);
    toluacls_setfunc(L, "getFloat", _xgame_preferences_getFloat);
    toluacls_setfunc(L, "setFloat", _xgame_preferences_setFloat);
    toluacls_setfunc(L, "getDouble", _xgame_preferences_getDouble);
    toluacls_setfunc(L, "setDouble", _xgame_preferences_setDouble);
    toluacls_setfunc(L, "getInteger", _xgame_preferences_getInteger);
    toluacls_setfunc(L, "setInteger", _xgame_preferences_setInteger);
    toluacls_setfunc(L, "getString", _xgame_preferences_getString);
    toluacls_setfunc(L, "setString", _xgame_preferences_setString);
    toluacls_setfunc(L, "deleteKey", _xgame_preferences_deleteKey);
    toluacls_setfunc(L, "flush", _xgame_preferences_flush);

    toluacls_createclassproxy(L);

    return 1;
}

static std::unordered_map<std::string, int> s_timer_tag;

static int _xgame_timer_killDelay(lua_State *L)
{
    lua_settop(L, 1);
    const char *tagstr = luaL_checkstring(L, 1);
    const std::string tag = std::string(tagstr);
    auto it = s_timer_tag.find(tag);
    if (it != s_timer_tag.end()) {
        xlua_unref(L, it->second);
        s_timer_tag.erase(it);
        xgame::timer::killDelay(tag);
    }
    return 0;
}

static int _xgame_timer_delay(lua_State *L)
{
    lua_settop(L, 2);
    float time = (float)luaL_checknumber(L, 1);
    unsigned int callback = xlua_reffunc(L, 2);
    xgame::timer::delay(time, [callback]() {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            xlua_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}

static int _xgame_timer_delayWithTag(lua_State *L)
{
    lua_settop(L, 3);
    size_t len;
    float time = (float)luaL_checknumber(L, 1);
    const char *tagstr = luaL_checklstring(L, 2, &len);
    if (len <= 0) {
        luaL_error(L, "key should not be empty!");
    }
    const std::string tag = std::string(tagstr);
    if (s_timer_tag.find(tag) != s_timer_tag.end()) {
        xlua_unref(L, s_timer_tag[tag]);
    }
    unsigned int callback = xlua_reffunc(L, 3);
    s_timer_tag[tag] = callback;
    xgame::timer::delayWithTag(time, tag, [callback]() {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pcall(L, 0, 0, top + 1);
            xlua_unref(L, callback);
        }
        lua_settop(L, top);
    });
    return 0;
}

static int _xgame_timer_schedule(lua_State *L)
{
    lua_settop(L, 2);
    float interval = (float)luaL_checknumber(L, 1);
    unsigned int callback = xlua_reffunc(L, 2);
    unsigned int id = xgame::timer::schedule(interval, [callback](float dt) {
        lua_State *L = xlua_cocosthread();
        int top = lua_gettop(L);
        lua_pushcfunction(L, xlua_errorfunc);
        xlua_getref(L, callback);
        if (lua_isfunction(L, -1)) {
            lua_pushnumber(L, dt);
            lua_pcall(L, 1, 0, top + 1);
        }
        lua_settop(L, top);
    });
    lua_pushinteger(L, ((uint64_t)callback << 32) | (uint64_t)id);
    return 1;
}

static int _xgame_timer_unschedule(lua_State *L)
{
    lua_settop(L, 1);
    uint64_t value = luaL_checkinteger(L, 1);
    unsigned int callback = value >> 32;
    unsigned int id = value & 0xFFFFFFFF;
    xlua_unref(L, callback);
    xgame::timer::unschedule(id);
    return 0;
}

static int luaopen_xgame_timer(lua_State *L)
{
    toluacls_class(L, "kernel.timer", nullptr);
    toluacls_setfunc(L, "killDelay", _xgame_timer_killDelay);
    toluacls_setfunc(L, "delay", _xgame_timer_delay);
    toluacls_setfunc(L, "delayWithTag", _xgame_timer_delayWithTag);
    toluacls_setfunc(L, "schedule", _xgame_timer_schedule);
    toluacls_setfunc(L, "unschedule", _xgame_timer_unschedule);

    toluacls_createclassproxy(L);

    return 1;
}

static int _xgame_window_visibleBounds(lua_State *L)
{
    auto rect = cocos2d::Director::getInstance()->getOpenGLView()->getVisibleRect();
    lua_pushinteger(L, rect.getMinX());
    lua_pushinteger(L, rect.getMaxX());
    lua_pushinteger(L, rect.getMaxY());
    lua_pushinteger(L, rect.getMinY());
    return 4;
}


static int _xgame_window_getDesignSize(lua_State *L)
{
    auto size = cocos2d::Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
    lua_pushnumber(L, size.width);
    lua_pushnumber(L, size.height);
    return 2;
}

static int _xgame_window_setDesignSize(lua_State *L)
{
    lua_settop(L, 3);
    cocos2d::Director::getInstance()->getOpenGLView()->setDesignResolutionSize(
        (float)luaL_checknumber(L, 1), (float)luaL_checknumber(L, 2),
        (ResolutionPolicy)luaL_checkinteger(L, 3));
    return 0;
}

static int _xgame_window_convertToCameraSpace(lua_State *L)
{
    cocos2d::Vec2 pt = cocos2d::Vec2(luaL_checknumber(L, 1), luaL_checknumber(L, 2));

    auto director = cocos2d::Director::getInstance();
    cocos2d::Mat4 w2l = director->getRunningScene()->getWorldToNodeTransform();
    cocos2d::Rect rect;
    rect.size = director->getOpenGLView()->getDesignResolutionSize();
    auto camera = director->getRunningScene()->getDefaultCamera();
    cocos2d::Vec3 Pn(pt.x, pt.y, -1), Pf(pt.x, pt.y, 1);
    Pn = camera->unprojectGL(Pn);
    Pf = camera->unprojectGL(Pf);

    //  then convert Pn and Pf to node space
    w2l.transformPoint(&Pn);
    w2l.transformPoint(&Pf);

    // Pn and Pf define a line Q(t) = D + t * E which D = Pn
    auto E = Pf - Pn;

    // second, get three points which define content plane
    //  these points define a plane P(u, w) = A + uB + wC
    cocos2d::Vec3 A = cocos2d::Vec3(rect.origin.x, rect.origin.y, 0);
    cocos2d::Vec3 B(rect.origin.x + rect.size.width, rect.origin.y, 0);
    cocos2d::Vec3 C(rect.origin.x, rect.origin.y + rect.size.height, 0);
    B = B - A;
    C = C - A;

    //  the line Q(t) intercept with plane P(u, w)
    //  calculate the intercept point P = Q(t)
    //      (BxC).A - (BxC).D
    //  t = -----------------
    //          (BxC).E
    cocos2d::Vec3 BxC;
    cocos2d::Vec3::cross(B, C, &BxC);
    auto BxCdotE = BxC.dot(E);
    auto t = (BxC.dot(A) - BxC.dot(Pn)) / BxCdotE;
    cocos2d::Vec3 P = Pn + t * E;

    lua_pushnumber(L, P.x);
    lua_pushnumber(L, P.y);

    return 2;
}

static int luaopen_xgame_window(lua_State *L)
{
    toluacls_class(L, "kernel.window", nullptr);
    toluacls_setfunc(L, "visibleBounds", _xgame_window_visibleBounds);
    toluacls_setfunc(L, "getDesignSize", _xgame_window_getDesignSize);
    toluacls_setfunc(L, "setDesignSize", _xgame_window_setDesignSize);
    toluacls_setfunc(L, "convertToCameraSpace", _xgame_window_convertToCameraSpace);

    toluacls_createclassproxy(L);

    return 1;
}

int luaopen_xgame(lua_State *L)
{
    xlua_require(L, "kernel.runtime", luaopen_xgame_runtime);
    xlua_require(L, "kernel.filesystem", luaopen_xgame_filesystem);
    xlua_require(L, "kernel.preferences", luaopen_xgame_preferences);
    xlua_require(L, "kernel.timer", luaopen_xgame_timer);
    xlua_require(L, "kernel.window", luaopen_xgame_window);
    return 0;
}
