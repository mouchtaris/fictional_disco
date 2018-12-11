# vim: et ts=2 sw=2

module ConfDirViews
  @conf : ConfDirStorage

  def conf
    @conf
  end

  def conf_sms_root
    @conf.root
  end

  def conf_project_root
    @conf.value :project_root
  end

  def conf_skeletor
    @conf.subconf :skeletor
  end

  def conf_structure
    @conf.subconf :structure
  end

  def conf_mod(name)
    conf_structure.subconf(:mods).list(name)
  end

  def each_conf_mod
    conf_structure.list(:mods).each do |mod_name|
      yield mod_name, conf_mod(mod_name)
    end
  end

  def conf_mods
    result = {} of String => Array(String)
    each_conf_mod do |name, mod|
      result[name] = mod
    end
    result
  end
end
